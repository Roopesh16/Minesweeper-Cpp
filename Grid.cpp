/**
 * @file Grid.cpp
 * @author Roopesh
 * @brief Defines function of Grid class
 * @version 0.1
 * @date 2024-01-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "HeaderFiles/Grid.h"
#include "HeaderFiles/Cell.h"
#include "HeaderFiles/State.h"
#include <iostream>
#include <queue>
using namespace std;

#define NUM_DEC 48

/// @brief Check if is first input or not
bool isFirst = true;
/// @brief Visited grid to check whether current cell has been visited or not
bool visited[N][N] = {false};

/**
 * @brief Takes input from user and sets grid and open the grid
 *
 * @param row Input row
 * @param col Input column
 */
void Grid::GetInput(int row, int col)
{
    if (isFirst)
    {
        SetupMines(row, col);
        SetCellValues();
        isFirst = false;
    }

    if (cells[row][col]->GetCellType() == EMPTY)
        OpenEmptyGrid(row, col, visited);
    else if (cells[row][col]->GetCellType() == NUMBER)
        cells[row][col]->SetCellState(OPEN);
    else
    {
        cells[row][col]->SetCellState(OPEN);
        State::SetState(OVER);
    }
    PrintGrid();
}

/**
 * @brief This takes random 10 places and setup mines
 *
 * @param row Input row to be omitted
 * @param col Input column to be omitted
 */
void Grid::SetupMines(int row, int col)
{
    int time = 10;
    int x, y;
    while (time > 0)
    {
        x = (rand() % N);
        y = (rand() % N);

        while ((x == row && y == col) || cells[x][y]->GetCellType() == MINE)
        {
            x = (rand() % N);
            y = (rand() % N);
        }

        cells[x][y]->SetCellType(MINE);
        time--;
    }
}

/**
 * @brief Sets cell value for each cell in the grid
 *
 */
void Grid::SetCellValues()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            SetCellValue(i, j);
        }
    }
}

/**
 * @brief Checks each cell and set a cell type and value for it
 *
 * @param row Cell row
 * @param col Cell column
 */
void Grid::SetCellValue(int row, int col)
{
    if (cells[row][col]->GetCellType() == MINE)
    {
        cells[row][col]->SetCellValue('*');
        return;
    }
    int mineCount = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < N && j >= 0 && j < N)
            {
                if (cells[i][j]->GetCellType() == MINE)
                    mineCount++;
            }
        }
    }

    if (mineCount == 0)
    {
        cells[row][col]->SetCellType(EMPTY);
        cells[row][col]->SetCellValue('0');
    }
    else
    {
        cells[row][col]->SetCellType(NUMBER);
        cells[row][col]->SetCellValue(char(mineCount + NUM_DEC));
    }
}

/**
 * @brief Check whether player has won the game or not
 *
 */
void Grid::CheckWinState()
{
    bool IsWin = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cells[i][j]->GetCellType() == NUMBER && cells[i][j]->GetCellState() == CLOSED)
            {
                IsWin = false;
            }
        }
    }

    if (IsWin)
        State::SetState(WIN);
}

/**
 * @brief This function opens all empty grid till it find a numbered grid
 *
 * @param row Input row
 * @param col Input column
 * @param visited Visited array
 */
void Grid::OpenEmptyGrid(int row, int col, bool visited[N][N])
{
    if (cells[row][col]->GetCellType() == NUMBER)
    {
        cells[row][col]->SetCellState(OPEN);
        return;
    }

    if (cells[row][col]->GetCellType() == MINE)
    {
        return;
    }

    visited[row][col] = true;
    cells[row][col]->SetCellState(OPEN);

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i >= 0 && i < N && j >= 0 && j < N)
            {
                if (visited[i][j] == false)
                {
                    visited[i][j] = true;
                    OpenEmptyGrid(i, j, visited);
                }
            }
        }
    }
}

/**
 * @brief Prints the open cells in the grid
 *
 */
void Grid::PrintGrid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cells[i][j]->GetCellState() == OPEN)
                cout << cells[i][j]->GetCellValue() << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}
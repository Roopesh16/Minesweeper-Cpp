#include "HeaderFiles/Grid.h"
#include "HeaderFiles/Cell.h"
#include "HeaderFiles/State.h"
#include <iostream>
#include <queue>
using namespace std;

bool isFirst = true;
bool visited[N][N] = {false};

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

void Grid::SetCellValues()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cells[i][j]->SetCellValue();
        }
    }
}

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

void Grid::OpenEmptyGrid(int row, int col, bool visited[N][N])
{
    if (row == N || col == N || row < 0 || col < 0)
    {
        return;
    }

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
        for (int j = col - 1; j < col + 1; j++)
        {
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                OpenEmptyGrid(i, j, visited);
            }
        }
    }
}

void Grid::PrintGrid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cells[i][j]->GetCellState() == OPEN)
                cout << cells[i][j]->GetCellValue();
            else
                cout << "-";
        }
        cout << endl;
    }
}

Cell **Grid::GetGrid()
{
    return *cells;
}

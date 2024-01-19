#include "HeaderFiles/Grid.h"
#include <iostream>
using namespace std;

bool isFirst = true;

void Grid::GetInput(int row, int col)
{
    if (isFirst)
    {
        SetupMines(row, col);
        SetCellValues();
    }

    if(grid[row][col] == EMPTY)
        OpenEmptyGrid();
    else if(grid[row][col] == NUMBER)
        grid[row][col].SetCellState(OPEN);
    else
    {
        grid[row][col].SetCellState(OPEN);
        //SetGameState(OVER);
    }

    PrintGrid();
}

void Grid::SetupMines(int row, int col)
{
    int time = 10;
    int x, y;
    while (time > 0)
    {
        x = (rand() % (N + 1));
        y = (rand() % (N + 1));

        while ((x == row && y == col) || grid[x][y].GetCellType() == MINE)
        {
            x = (rand() % (N + 1));
            y = (rand() % (N + 1));
        }

        grid[x][y].SetCellType = MINE;
        time--;
    }
}

void Grid::SetCellValues()
{
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; i <= col + 1; j++)
        {
            grid[i][j].SetCellValue();
        }
    }
}

void Grid::OpenEmptyGrid(int row,int col)
{
    
}


#include"HeaderFiles/Cell.h"
#ifndef GRID_H
#define GRID_H

#define N 9
class Grid
{
private:
    Cell grid[N][N];

public:
    Grid()
    {
        for (int i = 0; i < N;i++)
        {
            for (int j = 0; j < N;j++)
            {
                grid[i][j].SetCellValue() = '0';
            }
        }
    }

    void GetInput(int, int);
    void SetupMines();
    void SetCellValues();
    void PrintGrid();
};

#endif
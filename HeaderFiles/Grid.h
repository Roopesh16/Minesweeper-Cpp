#include "Cell.h"

#ifndef GRID_H
#define GRID_H

#define N 9

class Grid
{
private:
    Cell *cells[N][N];
    void SetupMines(int, int);
    void SetCellValues();
    void OpenEmptyGrid(int, int);
    void PrintGrid();

public:
    Grid()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cells[i][j] = new Cell(i, j);
            }
        }
    }

    void GetInput(int, int);
};

#endif
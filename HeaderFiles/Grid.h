/**
 * @file Grid.h
 * @author Roopesh
 * @brief Grid header file for grid used in the game
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Cell.h"

#ifndef GRID_H
#define GRID_H

#define N 9

/**
 * @brief Grid class to setup grid and check each cell value
 * 
 */
class Grid
{
private:
    Cell *cells[N][N];
    void SetupMines(int, int);
    void SetCellValues();
    void SetCellValue(int, int);
    void CheckWinState();
    void OpenEmptyGrid(int, int,bool [N][N]);
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
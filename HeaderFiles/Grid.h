#ifndef GRID_H
#define GRID_H

#define N 9

class Grid
{
private:
    char grid[N][N] = {'0'};
public:
    void GetInput(int row, int col);
    void SetupMines();
    void SetCellValues();
    void Print();
};

#endif
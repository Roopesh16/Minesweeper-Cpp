#ifndef GRID_H
#define GRID_H

#define N 9

class Grid
{
private:
    char grid[N][N] = {'0'};
public:
    void Print();
    void SetupMines();
    void SetCellValues();
    void GetInput(int row, int col);
};

#endif
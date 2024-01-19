#include "HeaderFiles/Grid.h"
#include <iostream>
using namespace std;

void Grid::SetCellValues()
{
    if (this.cellType == MINE)
        return;

    for (int i = row - 1; i <= row + 1;i++)
    {
        for (int j = col - 1; i <= col + 1;j++)
        {
            grid[i][j].SetCellValue();
        }
    }
}
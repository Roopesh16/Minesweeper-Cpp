#include "HeaderFiles/Cell.h"
#include "HeaderFiles/Grid.h"
#include <iostream>
using namespace std;

void Cell::SetCellState(CellState cellState)
{
    this->cellState = cellState;
}

CellState Cell::GetCellState()
{
    return cellState;
}

void Cell::SetCellType(CellType cellType)
{
    this->cellType = cellType;
}

CellType Cell::GetCellType()
{
    return cellType;
}

void Cell : SetCellValue()
{
    if (this.cellType == MINE)
    {
        this.cellValue = '*';
        return;
    }

    int mineCount = 0;

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (this.cellType == MINE)
                mineCount++;
        }
    }

    if (mineCount == 0)
    {
        SetCellType(EMPTY);
    }
    else
    {
        SetCellType(NUMBER);
    }

    this.cellValue = (char)cellValuel;
}

char Cell::GetCellValue()
{
    return cellValue;
}

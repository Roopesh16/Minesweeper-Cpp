#include "HeaderFiles/Cell.h"
#include "HeaderFiles/Grid.h"
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

void Cell :: SetCellValue()
{
    if (cellType == MINE)
    {
        cellValue = '*';
        return;
    }

    int mineCount = 0;

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (cellType == MINE)
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

    this->cellValue = (char)mineCount;
}

char Cell::GetCellValue()
{
    return Cell::cellValue;
}

#include "HeaderFiles/Cell.h"
#include "HeaderFiles/Grid.h"
#include <iostream>
using namespace std;

Grid grid;

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

void Cell ::SetCellValue()
{
    cout << "set";
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
            if (grid.GetGrid()[i][j].cellType == MINE)
            {
                cout << 2;
                mineCount++;
            }

            cout << 3;
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

    cellValue = char(mineCount);
    cout << mineCount << "\n";
}

char Cell::GetCellValue()
{
    return cellValue;
}

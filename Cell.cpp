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

void Cell::SetCellValue(char cellValue)
{
    this->cellValue = cellValue;
}

char Cell::GetCellValue()
{
    return cellValue;
}

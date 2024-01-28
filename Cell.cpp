/**
 * @file Cell.cpp
 * @author Roopesh
 * @brief Function definition for cell class
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "HeaderFiles/Cell.h"
#include "HeaderFiles/Grid.h"
#include <iostream>
using namespace std;

/**
 * @brief This sets a new cell state
 * 
 * @param cellState New cell state to set
 */
void Cell::SetCellState(CellState cellState)
{
    this->cellState = cellState;
}

/**
 * @brief This returns current cell state
 * 
 * @return CellState Return current cell state
 */
CellState Cell::GetCellState()
{
    return cellState;
}

/**
 * @brief This sets a new cell type
 * 
 * @param cellType New cell type to set
 */
void Cell::SetCellType(CellType cellType)
{
    this->cellType = cellType;
}

/**
 * @brief Returns curren cell type
 * 
 * @return CellType Current cell type
 */
CellType Cell::GetCellType()
{
    return cellType;
}

/**
 * @brief This sets cell value for the cell calculated from grid
 * 
 * @param cellValue New cell value
 */
void Cell::SetCellValue(char cellValue)
{
    this->cellValue = cellValue;
}

/**
 * @brief Returns current cell value
 * 
 * @return char Current cell value
 */
char Cell::GetCellValue()
{
    return cellValue;
}

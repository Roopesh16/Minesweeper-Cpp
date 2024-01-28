/**
 * @file Cell.h
 * @author Roopesh
 * @brief Header file storing each cell data
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CELL_H
#define CELL_H

/**
 * @brief Cell Type enum to specify what kind of Cell it is
 * 
 */
enum CellType
{
    EMPTY,
    NUMBER,
    MINE,
};

/**
 * @brief Cell State enum to specify whether cell is open or not
 * 
 */
enum CellState
{
    OPEN,
    CLOSED
};

/**
 * @brief Cell Class which stores row, column, Cell Type and Cell State data for each cell
 * 
 */
class Cell
{
private:
    int row;
    int col;
    char cellValue;
    CellType cellType;
    CellState cellState;

public:
    Cell(int row, int col)
    {
        this->row = row;
        this->col = col;
        cellValue = '0';
        cellType = EMPTY;
        cellState = CLOSED;
    }

    void SetCellType(CellType);
    CellType GetCellType();
    void SetCellState(CellState);
    CellState GetCellState();
    void SetCellValue(char);
    char GetCellValue();
};

#endif
#ifndef CELL_H
#define CELL_H

enum CellType
{
    NUMBER,
    MINE,
    EMPTY
};

enum CellState
{
    OPEN,
    CLOSED
};

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
    void SetCellValue();
    char GetCellValue();
};

#endif
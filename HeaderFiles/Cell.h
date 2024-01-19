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
    int mineCount;
    CellType cellType;
    CellState cellState;

public:
    Cell(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    void SetCellType(CellType cellType);
    void SetCellState(CellState cellState);
    void SetMineCount();
    CellType GetCellType();
    CellState GetCellState();
    char GetMineCount();
};

#endif
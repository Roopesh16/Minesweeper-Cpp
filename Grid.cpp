#include "HeaderFiles/Grid.h"
#include "HeaderFiles/Cell.h"
#include "HeaderFiles/State.h"
#include <iostream>
using namespace std;

bool isFirst = true;

void Grid::GetInput(int row, int col)
{
    if (isFirst)
    {
        SetupMines(row, col);
        SetCellValues();
        isFirst = false;
    }

    if (cells[row][col]->GetCellType() == EMPTY)
        OpenEmptyGrid(row, col);
    else if (cells[row][col]->GetCellType() == NUMBER)
        cells[row][col]->SetCellState(OPEN);
    else
    {
        cells[row][col]->SetCellState(OPEN);
        SetState(OVER);
    }

    PrintGrid();
}

void Grid::SetupMines(int row, int col)
{
    int time = 10;
    int x, y;
    while (time > 0)
    {
        x = (rand() % (N + 1));
        y = (rand() % (N + 1));

        while ((x == row && y == col) || cells[x][y]->GetCellType() == MINE)
        {
            x = (rand() % (N + 1));
            y = (rand() % (N + 1));
        }

        cells[x][y]->SetCellType(MINE);
        time--;
    }
}

void Grid::SetCellValues()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; i < N; j++)
        {
            cells[i][j]->SetCellValue();
        }
    }
}

void Grid::OpenEmptyGrid(int row, int col)
{
    cells[row][col]->SetCellState(OPEN);
}

void Grid::PrintGrid()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cells[i][j]->GetCellState() == OPEN)
                cout << cells[i][j]->GetCellValue();
            else
                cout << " ";
        }
        cout << endl;
    }
}

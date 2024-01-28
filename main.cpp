/**
 * @file main.cpp
 * @author Roopesh
 * @brief Main file where info is displayed and user input is taken
 * @version 0.1
 * @date 2024-01-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "HeaderFiles/Grid.h"
#include "HeaderFiles/Cell.h"
#include "HeaderFiles/State.h"
#include <iostream>
#include <iomanip>
using namespace std;

std::ostream &bold_on(std::ostream &os) { return os << "\e[1m"; }

std::ostream &bold_off(std::ostream &os) { return os << "\e[0m"; }

/**
 * @brief This prints the game rules
 *
 */
void BasicInfo()
{
    cout << bold_on << setw(45) << "MINESWEEPER\n\n"
         << bold_off;
    cout << "Minesweeper is a classic game which everyone has played but no one knows the rule of! So here are the rules - \n";
    cout << "1. You can input between 0-9 as row and column.\n";
    cout << "2. When the grid opens, you will see numbers on the cell. This number represents the number of mine adjacent to current cell\n";
    cout << "3. If you open a mine, then GAME OVER.\n";
    cout << "4. If you avoid all the mines, then you win\n";
    cout << "\n";
}

/**
 * @brief Main function where user input is taken
 *
 * @return int
 */
int main()
{
    BasicInfo();
    State::SetState(PLAY);

    Grid *grid = new Grid();

    while (State::GetState() == PLAY)
    {
        int row, col;
        cout << "\nEnter Row : ";
        cin >> row;
        cout << "Enter Column : ";
        cin >> col;

        grid->GetInput(row, col);
    }

    if (State::GetState() == WIN)
    {
        cout << bold_on << "GAME WON!!!\n" << bold_off;
    }
    else
    {
        cout << bold_on << "GAME OVER!!!\n" << bold_off;
    }

    int n;
    cin>>n;
}
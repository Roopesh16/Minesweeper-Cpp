#include "HeaderFiles/State.h"
using namespace std;

void State::SetState(GameState newState)
{
    state = newState;
}

GameState State::GetState()
{
    return state;
}
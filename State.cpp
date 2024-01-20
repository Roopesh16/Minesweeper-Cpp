#include "HeaderFiles/State.h"

void State::SetState(GameState newState)
{
    state = newState;
}

GameState State::GetState()
{
    return state;
}
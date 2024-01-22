#include "HeaderFiles/State.h"

GameState State::state = NONE;

void State::SetState(GameState newState)
{
    state = newState;
}

GameState State::GetState()
{
    return state;
}
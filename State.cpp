/**
 * @file State.cpp
 * @author Roopesh
 * @brief Defines function in State class
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "HeaderFiles/State.h"

/// @brief State variable holding current state
GameState State::state = NONE;

/**
 * @brief Sets new game state
 * 
 * @param newState New state to be set
 */
void State::SetState(GameState newState)
{
    state = newState;
}

/**
 * @brief Return the current game state
 * 
 * @return GameState Current game state
 */
GameState State::GetState()
{
    return state;
}
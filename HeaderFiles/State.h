/**
 * @file State.h
 * @author Roopesh
 * @brief State header file to keep track of game states
 * @version 0.1
 * @date 2024-01-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef STATE_H
#define STATE_H

/**
 * @brief Game state enum to store at which state our game currently is
 * 
 */
enum GameState
{
    NONE,
    PLAY,
    WIN,
    OVER
};

class State
{
private:
public:
    static GameState state;
    static void SetState(GameState);
    static GameState GetState();
};

#endif
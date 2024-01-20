#ifndef STATE_H
#define STATE_H

enum State
{
    PLAY,
    WIN,
    OVER
};

State state;

State GetState()
{
    return state;
}

void SetState(State newState)
{
    state = newState;
}

#endif
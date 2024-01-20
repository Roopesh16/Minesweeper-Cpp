#ifndef STATE_H
#define STATE_H

enum GameState
{
    PLAY,
    WIN,
    OVER
};

static class State
{
private:
    static GameState state;

public:
    void SetState(GameState newState);

    GameState GetState();
};
#endif
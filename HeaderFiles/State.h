#ifndef STATE_H
#define STATE_H

enum GameState
{
    PLAY,
    WIN,
    OVER
};

class State
{
private:
    static GameState state;

public:
    static void SetState(GameState);
    static GameState GetState();
};

#endif
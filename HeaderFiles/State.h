#ifndef STATE_H
#define STATE_H

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
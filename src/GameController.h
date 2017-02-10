#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <SDL2/SDL.h>
#include <queue>

#include "StateMachine.h"
#include "State.h"

class GameController: public StateMachine
{
    public:
    GameController();
    int GameLoop();

    void ChangeState(State& state);
    State* GetState();
    void Cycle();

    private:
    enum GameState {ST_SHOW_SPLASH, ST_SHOW_MAIN_MENU, ST_MAIN_GAME, ST_EXIT};
    GameState state_;

    std::queue<SDL_KeyboardEvent> key_queue_;
};

#endif

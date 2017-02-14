#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StateMachine.h"
#include "State.h"
#include "Renderer.h"

#include <SDL2/SDL.h>
#include <queue>
#include <vector>
#include <memory>

class GameController: public StateMachine
{
    public:
    GameController();
    int GameLoop();

    void AddState(std::shared_ptr<State>);
    State* GetState();
    void Cycle();

    Renderer renderer_;
    private:
    enum GameState {ST_SHOW_SPLASH, ST_SHOW_MAIN_MENU, ST_MAIN_GAME, ST_EXIT};
    std::vector<std::shared_ptr<State>> states_;

    std::queue<SDL_KeyboardEvent> key_queue_;
};

#endif

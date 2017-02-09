#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <SDL2/SDL.h>
#include <queue>

class GameController
{
    public:
    GameController();
    int GameLoop();
    private:
    enum GameState {ST_SHOW_SPLASH, ST_SHOW_MAIN, ST_EXIT};
    GameState state_;

    std::queue<SDL_KeyboardEvent> key_queue_;
};

#endif
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

class GameController
{
    public:
    GameController();
    int GameLoop();
    private:
    enum GameState {ST_SHOW_SPLASH, ST_SHOW_MAIN, ST_EXIT};
    GameState mState;
};

#endif
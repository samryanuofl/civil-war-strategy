#include "GameController.h"

#include <iostream>


const SDL_Keycode DEFAULT_KEY = SDL_SCANCODE_HELP;

/////////////////////////////////////////////////////////////////////////////////
// Public Functions
/////////////////////////////////////////////////////////////////////////////////
GameController::GameController(): state_(ST_SHOW_SPLASH)
{

}

int GameController::GameLoop()
{
    SDL_Event e;
    int isEvent = SDL_PollEvent(&e);
    SDL_Keycode key_pressed = DEFAULT_KEY;
    if(e.type == SDL_KEYUP) {
        key_pressed = e.key.keysym.sym;
        key_queue_.push(e.key);
    }

    switch(state_)
    {
        case ST_SHOW_SPLASH:
            if(key_pressed != DEFAULT_KEY) {
                std::cout << "Exiting game" << std::endl;
                std::cout << key_pressed << std::endl;
                state_ = ST_EXIT;
            }
        break;
        case ST_SHOW_MAIN_MENU:
        break;
        case ST_MAIN_GAME:
        break;
        case ST_EXIT:
            return -1;
        break;
    }

    return 0;
}

void GameController::ChangeState(State& state)
{

}

State* GameController::GetState()
{
    return NULL;
}

void GameController::Cycle()
{
}

/////////////////////////////////////////////////////////////////////////////////
// Private Functions
/////////////////////////////////////////////////////////////////////////////////


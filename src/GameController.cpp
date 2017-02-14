#include "GameController.h"
#include "StateIntro.h"

#include <iostream>
#include <cstddef>


const SDL_Keycode DEFAULT_KEY = SDL_SCANCODE_HELP;

/////////////////////////////////////////////////////////////////////////////////
// Public Functions
/////////////////////////////////////////////////////////////////////////////////
GameController::GameController()
{
    renderer_.Init(1024, 768);
    std::shared_ptr<State> intro_state(new StateIntro(renderer_));
    states_.push_back(intro_state);
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

    int x = 1;
    switch(x)
    {
        case ST_SHOW_SPLASH:
            if(key_pressed != DEFAULT_KEY) {
                std::cout << "Exiting game" << std::endl;
                std::cout << key_pressed << std::endl;
                return -1;
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

void GameController::AddState(std::shared_ptr<State> state)
{
    states_.push_back(state);
}

State* GameController::GetState()
{
    return NULL;
}

void GameController::Cycle()
{
    for(auto& elem: states_) {
        elem->Cycle(this);
    }
}

/////////////////////////////////////////////////////////////////////////////////
// Private Functions
/////////////////////////////////////////////////////////////////////////////////


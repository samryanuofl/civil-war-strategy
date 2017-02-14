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

void GameController::AddState(std::shared_ptr<State> state)
{
    states_.push_back(state);
}

State* GameController::GetState()
{
    return NULL;
}

int GameController::Cycle()
{
    SDL_Event e;
    int isEvent = SDL_PollEvent(&e);
    SDL_Keycode key_pressed = DEFAULT_KEY;
    if(e.type == SDL_KEYUP) {
        key_pressed = e.key.keysym.sym;
        key_queue_.push(e.key);
    }
    else if(SDL_QUIT == e.type) {
        return -1;
    }


    for(auto& elem: states_) {
        elem->Cycle(this);
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Private Functions
/////////////////////////////////////////////////////////////////////////////////


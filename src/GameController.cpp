#include "GameController.h"

#include <iostream>
#include <SDL2/SDL.h>

/////////////////////////////////////////////////////////////////////////////////
// Public Functions
/////////////////////////////////////////////////////////////////////////////////
GameController::GameController(): mState(ST_SHOW_SPLASH)
{

}

int GameController::GameLoop()
{
    SDL_Event e;
    int isKeyPressed = SDL_PollEvent(&e);

    switch(mState)
    {
        case ST_SHOW_SPLASH:
            if(0 != isKeyPressed) {
                if(e.type == SDL_KEYDOWN) {
                    mState = ST_EXIT;
                }
            }
        break;
        case ST_SHOW_MAIN:
        break;
        case ST_EXIT:
            return -1;
        break;
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Private Functions
/////////////////////////////////////////////////////////////////////////////////


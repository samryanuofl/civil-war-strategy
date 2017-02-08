#include "GameController.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[])
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Error";
        return -1;
    }

    window = SDL_CreateWindow("Civil War Strategy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(NULL == window) {
        std::cout << "SDL Create Window Error";
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
    SDL_Surface* mapSurface = IMG_Load("../res/EuropeMap.png");
    if(NULL == mapSurface) {
        std::cout << "SDL Load BMP Error: " << std::string(SDL_GetError()) << std::endl;
    }
    SDL_BlitSurface(mapSurface, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);
    
    GameController gc;
    SDL_Delay(2000);
    // while(0 == gc.GameLoop())


    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
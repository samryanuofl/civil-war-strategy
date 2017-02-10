#include "Renderer.h"
#include <iostream>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
    //dtor
}

int Renderer::Init(int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Error";
        return -1;
    }

    window_ = SDL_CreateWindow("Civil War Strategy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(NULL == window_) {
        std::cout << "SDL Create Window Error";
    }
    screen_surface_ = SDL_GetWindowSurface(window_);


    return 0;
}

int Renderer::Render(const IRenderable *renderable)
{

    return 0;
}

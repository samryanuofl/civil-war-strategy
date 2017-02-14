#include "Renderer.h"
#include <iostream>
#include <cstddef>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

int Renderer::Init(int width, int height)
{
    window_dimensions_.h = height;
    window_dimensions_.w = width;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Error";
        return -1;
    }

    window_ = SDL_CreateWindow("Civil War Strategy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(NULL == window_) {
        std::cout << "SDL Create Window Error";
        return -1;
    }

    int img_flags = IMG_INIT_PNG;
    if(!IMG_Init(img_flags) & img_flags) {
        std::cout << "Failed to initialize IMG";
        return -1;
    }

    screen_surface_ = SDL_GetWindowSurface(window_);

    if(nullptr == screen_surface_) {
        std::cout << "screen surface NULL";
    }


    return 0;
}

int Renderer::RenderSprite(SpriteInfo &sprite)
{
    std::cout << "Render sprite";
    SDL_Surface *sprite_surface = IMG_Load(sprite.GetSpritePath().c_str());
    if(nullptr == sprite_surface) {
        // Error handling
        std::cout << "Sprite error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Surface *optimized_surface = SDL_ConvertSurface(sprite_surface, screen_surface_->format, 0);
    if(nullptr == optimized_surface) {
        std::cout << "SL Convert Error";
        return -1;
    }

    SDL_FreeSurface(sprite_surface);
    SDL_BlitSurface(optimized_surface, NULL, screen_surface_, NULL);
    SDL_UpdateWindowSurface(window_);
    return 0;
}

int Renderer::Render(const IRenderable *renderable)
{
}

int Renderer::GetWindowHeight()
{
    return window_dimensions_.h;
}

int Renderer::GetWindowWidth()
{
    return window_dimensions_.w;
}


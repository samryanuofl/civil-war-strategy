#include "Renderer.h"
#include "spdlog.h"

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
        spdlog::get("spdconsole")->error("SDL Init Error: {}", SDL_GetError());
        return -1;
    }

    window_ = SDL_CreateWindow("Civil War Strategy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(NULL == window_) {
        spdlog::get("spdconsole")->error("SDL Create Window error: {}", SDL_GetError());
        return -1;
    }

    int img_flags = IMG_INIT_PNG;
    if((!IMG_Init(img_flags)) & img_flags) {
        spdlog::get("spdconsole")->error("SDL IMG Init error: {}", SDL_GetError());
        return -1;
    }

    screen_surface_ = SDL_GetWindowSurface(window_);

    if(nullptr == screen_surface_) {
        spdlog::get("spdconsole")->error("SDL Get Window Surface error: {}", SDL_GetError());
        return -1;
    }


    return 0;
}

int Renderer::RenderSprite(SpriteInfo &sprite)
{
    SDL_Surface *sprite_surface = IMG_Load(sprite.GetSpritePath().c_str());
    if(nullptr == sprite_surface) {
        // Error handling
        spdlog::get("spdconsole")->info("SDL IMG_Load error: {}", SDL_GetError());
        return -1;
    }

    SDL_Surface *optimized_surface = SDL_ConvertSurface(sprite_surface, screen_surface_->format, 0);
    if(nullptr == optimized_surface) {
        spdlog::get("spdconsole")->error("SDL Convert Surface error: {}", SDL_GetError());
        return -1;
    }

    SDL_FreeSurface(sprite_surface);
    if(SDL_BlitSurface(optimized_surface, NULL, screen_surface_, NULL)) {
        spdlog::get("spdconsole")->error("SDL Blit Surface error: {}", SDL_GetError());
    }
    SDL_UpdateWindowSurface(window_);
    return 0;
}

int Renderer::GetWindowHeight()
{
    return window_dimensions_.h;
}

int Renderer::GetWindowWidth()
{
    return window_dimensions_.w;
}


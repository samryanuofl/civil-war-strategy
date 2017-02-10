#ifndef RENDERER_H
#define RENDERER_H

#include "IRenderable.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();

        int Init(int width, int height);
        int Render(const IRenderable *renderable);
    private:
        SDL_Window* window_;
        SDL_Surface* screen_surface_;
};

#endif // RENDERER_H

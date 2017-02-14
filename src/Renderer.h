#ifndef RENDERER_H
#define RENDERER_H

#include "IRenderable.h"
#include "SpriteInfo.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();

        int Init(int width, int height);
        int RenderSprite(SpriteInfo &sprite);
        int Render(const IRenderable *renderable);

        int GetWindowHeight();
        int GetWindowWidth();
    private:
        SDL_Window* window_;
        SDL_Surface* screen_surface_;
        SDL_Rect window_dimensions_;
};

#endif // RENDERER_H

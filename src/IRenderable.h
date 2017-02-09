#include <SDL2/SDL.h>

#include <string>

class IRenderable
{
    public:
    virtual std::string GetText() = 0;
    virtual SDL_Rect GetTextRect() = 0;
    virtual std::string GetSpritePath() = 0;
    virtual SDL_Rect GetSpriteRect() = 0;
};
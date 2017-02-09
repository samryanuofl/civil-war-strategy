#ifndef SPRITEINFO_H
#define SPRITEINFO_H

#include <SDL2/SDL.h>
#include <string>

class SpriteInfo
{
    public:
        SpriteInfo();
        virtual ~SpriteInfo();
        std::string GetText();
        SDL_Rect GetTextRect();
        std::string GetSpritePath();
        SDL_Rect GetSpriteRect();
        bool isVisible();
    protected:
    private:
};

#endif // SPRITEINFO_H

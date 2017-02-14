#ifndef SPRITEINFO_H
#define SPRITEINFO_H

#include <SDL2/SDL.h>
#include <string>

class SpriteInfo
{
    public:
        SpriteInfo(std::string sprite_path, SDL_Point sprite_point, std::string text = std::string(), SDL_Rect text_rec = SDL_Rect());
        virtual ~SpriteInfo();

        std::string GetText();
        SDL_Rect GetTextRect();
        std::string GetSpritePath();
        SDL_Point GetSpritePos();
        bool isVisible();
    protected:
    private:
        std::string sprite_path_;
        std::string text_;
        SDL_Point sprite_point_;
        SDL_Rect text_rec_;
};

#endif // SPRITEINFO_H

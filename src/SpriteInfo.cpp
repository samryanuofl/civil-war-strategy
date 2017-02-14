#include "SpriteInfo.h"

SpriteInfo::SpriteInfo(std::string sprite_path, SDL_Point sprite_point, std::string text, SDL_Rect text_rec) :
sprite_path_(sprite_path),
sprite_point_(sprite_point),
text_(text),
text_rec_(text_rec)
{
}

SpriteInfo::~SpriteInfo()
{
    //dtor
}

std::string SpriteInfo::GetText()
{
    return text_;
}

SDL_Rect SpriteInfo::GetTextRect()
{
    return text_rec_;
}

std::string SpriteInfo::GetSpritePath()
{
    return sprite_path_;
}

SDL_Point SpriteInfo::GetSpritePos()
{
    return sprite_point_;
}

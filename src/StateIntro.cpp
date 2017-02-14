#include "StateIntro.h"
#include "StateMachine.h"
#include "SpriteInfo.h"

StateIntro::StateIntro(Renderer &renderer): renderer_(renderer)
{
}


void StateIntro::Start()
{
    const SDL_Point sprite_point = {0, 0};
    const std::string sprite_path("res/splash-lincoln-gage-skidmore.png");
    SpriteInfo si(sprite_path, sprite_point);
    renderer_.RenderSprite(si);
//    renderer_.RenderSprite()
}

void StateIntro::Cycle(StateMachine *state_machine)
{

}

void StateIntro::Exit()
{

}

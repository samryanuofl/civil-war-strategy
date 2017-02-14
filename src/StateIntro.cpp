#include "StateIntro.h"
#include "StateMachine.h"
#include "SpriteInfo.h"

static const std::string SPRITE_PATH_ = "res/splash-lincoln-gage-skidmore.png";
static const SDL_Point SPRITE_POINT_ = {0, 0};

StateIntro::StateIntro(Renderer &renderer): renderer_(renderer)
{
}


void StateIntro::Start()
{

}

void StateIntro::Cycle(StateMachine *state_machine)
{
    const SDL_Point sprite_point = {0, 0};
    const std::string sprite_path("res/splash-lincoln-gage-skidmore.png");
    SpriteInfo si(sprite_path, sprite_point);
    renderer_.RenderSprite(si);
}

void StateIntro::Exit()
{

}

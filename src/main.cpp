#include "GameController.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "Renderer.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

void TestRenderer()
{
    std::cout << "Creating renderer" << std::endl;
    Renderer r;
    r.Init(1024, 768);
    SDL_Point point = {0, 0};
    SpriteInfo si("res/splash-lincoln-gage-skidmore.png", point);
    std::cout << "Test rendering" << std::endl;
    r.RenderSprite(si);
    SDL_Delay(4000);
}

int main(int argc, char* args[])
{
//    TestRenderer();
//    return 0;

    GameController gc;

    while (gc.Cycle() == 0);

    return 0;
}

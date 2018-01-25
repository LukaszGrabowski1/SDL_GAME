

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "MathUtil.hpp"
#include <math.h>
#include <stdio.h>
#include "Game.hpp"
#include "TextureManager.hpp"

Game *game = nullptr;
int main(int argc, char *argv[])
{
    game = new Game();
    game->init();
    
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    
    Uint32 frameStart;
    int frameTime;

    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    
    
        
    game->clean();
    return 0;
}



//
//  Background.cpp
//  SDL_game
//
//  Created by Łukasz Grabowski on 21.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#include "Background.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"

Background::Background(const char* file)
{
    objTexture = TextureManager::loadTexture(file);
}


void Background::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, NULL);
}

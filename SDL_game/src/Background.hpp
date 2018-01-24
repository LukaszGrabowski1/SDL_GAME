//
//  Background.hpp
//  SDL_game
//
//  Created by Łukasz Grabowski on 21.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#ifndef Background_hpp
#define Background_hpp
#include "Game.hpp"
class Background{
public:
    Background(const char* file);
    ~Background();
    void update();
    void render();
    
private:
    SDL_Texture *objTexture;
};
#endif /* Background_hpp */

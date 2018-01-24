//
//  Collision.hpp
//  SDL_game
//
//  Created by Łukasz Grabowski on 21.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include "Map.hpp"
#include "Car.hpp"
#include "Game.hpp"
class Collision{
public:
    Collision();
    ~Collision();
    void detectCollision(Game *map, Car *car);
    bool detectCollisionWithWall(SDL_Rect wall, Car *car);
};
#endif /* Collision_hpp */

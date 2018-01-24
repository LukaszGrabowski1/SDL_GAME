//
//  Collision.cpp
//  SDL_game
//
//  Created by Łukasz Grabowski on 21.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#include "Collision.hpp"
#include "Map.hpp"
#include "Car.hpp"
#include "Global.hpp"
#include "Game.hpp"

Collision::Collision(){}

void Collision::detectCollision(Game *game, Car *car){
    Map *map = game->mapToDisplay;
    for(auto &wall: map->getWalls()) {
        if(detectCollisionWithWall(wall, car))
            game->stopGame();
    }
    
    for(auto &finish: map->getFinishes()) {
        if(detectCollisionWithWall(finish, car)){
            game->gameWon();
        }
    }
}

bool Collision::detectCollisionWithWall(SDL_Rect wall, Car *car){
    return (car->y + CAR_HEIGHT > wall.y +3)
            && (wall.x + wall.w - 3> car->x)
            && (wall.y + wall.h -3 > car->y)
            && (wall.x + 3 < car->x + CAR_WIDTH);
    
}

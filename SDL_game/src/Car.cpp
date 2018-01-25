//
//  Car.cpp
//  SDL_game
//
//  Created by Łukasz Grabowski on 21.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#include "Car.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "MathUtil.hpp"
#include "Global.hpp"
#include "Map.hpp"

Car::Car(const char* file)
{
    objTexture = TextureManager::loadTexture(file);
    x = 0;
    y = 640 - CAR_HEIGHT;
    dx = 0;
    dy = 0;
    gdx = 0;
    gdy = 0;
    ang = 90;
}

Car::~Car(){};

void Car::handleEvents(){
    const float acc = 2.0f;
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_LEFT])
    {
        ang -= 2;
    }
    if(state[SDL_SCANCODE_RIGHT])
    {
        ang += 2;
    }
    if(state[SDL_SCANCODE_UP])
    {
        float cdx = sinf(radiansFromDegrees(ang))*acc*0.1;
        float cdy = -cosf(radiansFromDegrees(ang))*acc*0.1;
        
        dx += cdx;
        dy += cdy;
    }
    if(state[SDL_SCANCODE_DOWN])
    {
        float cdx = sinf(radiansFromDegrees(ang))*0.1;
        float cdy = -cosf(radiansFromDegrees(ang))*0.1;
        
        dx += -cdx;
        dy += -cdy;
    }

}

void Car::update(){
    
    const float w = 14*2, h = 22*2;
    
    if(x < 5)
    {
        if(gdx < 0)
            gdx *= -1;
        if(dx < 0)
            dx *= -1;
    }
    
    if(x+w > SCREEN_WIDTH - 5){
        if(gdx > 0)
            gdx *= -1;
        if(dx > 0)
            dx *= -1;
    }
    
    if(y < -2){
        if(gdy < 0)
            gdy *= -1;
        if(dy < 0)
            dy *= -1;
    }
    
    if(y+h > SCREEN_HEIGHT + 5){
        if(gdy > 0)
            gdy *= -1;
        if(dy > 0)
            dy *= -1;
    }
    
    x += dx;
    y += dy;
    x += gdx;
    y += gdy;
    dx *= 0.96;
    dy *= 0.96;
    gdx *= 0.92;
    gdy *= 0.92;
};

void Car::render()
{
    SDL_Rect rec;
    rec.x = x;
    rec.y = y;
    rec.w = CAR_WIDTH;
    rec.h = CAR_HEIGHT;
    SDL_RenderCopyEx(Game::renderer, objTexture, NULL, &rec, ang, NULL, SDL_FLIP_NONE);
};

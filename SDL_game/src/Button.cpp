//
//  Open.cpp
//  SDL_game
//
//  Created by Łukasz Grabowski on 24.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#include <stdio.h>
#include "TextureManager.hpp"
#include "Button.h"

Button::Button(){}
Button::Button( int x, int y, int w, int h)
{
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    //Set the default sprite
    clip = &clips[ CLIP_MOUSEOUT ];
    
}

void Button::handle_events(SDL_Event *event)
{
    //The mouse offsets
    int x = 0, y = 0;
    //If the mouse moved
    if( event->type == SDL_MOUSEMOTION )
    {
        //Get the mouse offsets
        x = event->motion.x;
        y = event->motion.y;

        //If the mouse is over the button
        if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOVER ];
        }
        //If not
        else
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOUT ];
        }
    }
    //If a mouse button was pressed
    if( event->type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event->button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event->button.x;
            y = event->button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set* the button sprite
                clip = &clips[ CLIP_MOUSEDOWN ];
            }
        }
    }
    //If a mouse button was released
    if( event->type == SDL_MOUSEBUTTONUP )
    {
        //If the left mouse button was released
        if( event->button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event->button.x;
            y = event->button.y;


            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                clip = &clips[ CLIP_MOUSEUP ];
                buttonclick = true;
            }
        }
    }
}

void Button::showButton()
{
    SDL_Rect dest;
    dest.x = box.x;
    dest.y = box.y;
    dest.h = box.h;
    dest.w = box.w;
    
    SDL_Rect source;
    source.y = clip->y;
    source.x = clip->x;
    source.h = clip->h;
    source.w = clip->w;
    SDL_RenderCopy(Game::renderer, tex, &source, &dest);
}

bool Button::load_files( const char * filename)
{
    tex = TextureManager::loadTexture(filename);
    if( tex == NULL )
        return false;
    return true;
}

void Button::set_clips()
{
    //Clip the sprite sheet
    clips[ CLIP_MOUSEOVER ].x = 0;
    clips[ CLIP_MOUSEOVER ].y = 0;
    clips[ CLIP_MOUSEOVER ].w = 180;
    clips[ CLIP_MOUSEOVER ].h = 50;
    
    clips[ CLIP_MOUSEOUT ].x = 180;
    clips[ CLIP_MOUSEOUT ].y = 0;
    clips[ CLIP_MOUSEOUT ].w = 180;
    clips[ CLIP_MOUSEOUT ].h = 50;
    
    clips[ CLIP_MOUSEDOWN ].x = 0;
    clips[ CLIP_MOUSEDOWN ].y = 50;
    clips[ CLIP_MOUSEDOWN ].w = 180;
    clips[ CLIP_MOUSEDOWN ].h = 50;
    
    clips[ CLIP_MOUSEUP ].x = 180;
    clips[ CLIP_MOUSEUP ].y = 50;
    clips[ CLIP_MOUSEUP ].w = 180;
    clips[ CLIP_MOUSEUP ].h = 50;
}


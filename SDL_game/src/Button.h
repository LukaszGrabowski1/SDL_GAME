//
//  Open.h
//  SDL_game
//
//  Created by Łukasz Grabowski on 24.01.2018.
//  Copyright © 2018 Łukasz Grabowski. All rights reserved.
//

#ifndef Open_h
#define Open_h

const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

class Button
{
public:
    SDL_Rect box;
    SDL_Rect* clip;
    Button();
    Button( int x, int y, int w, int h);
    void handle_events(SDL_Event *event);
    void showButton();
    bool buttonclick = false;
    SDL_Texture *tex;
    SDL_Rect clips[4];
    bool load_files( const char * filename);
    void set_clips();
};

#endif /* Open_h */

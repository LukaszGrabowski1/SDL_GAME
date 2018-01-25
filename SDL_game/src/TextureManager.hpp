#ifndef TextureManager_hpp
#define TextureManager_hpp

#include "Game.hpp"

// Code from YouTube Tutorial - Let's Make Games
class TextureManager{
public:
    static SDL_Texture *loadTexture(const char* fileName);
    static void draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
};

#endif /* TextureManager_hpp */

#include "TextureManager.hpp"

SDL_Texture* TextureManager::loadTexture(const char *fileName)
{
    SDL_Surface *tempSurface = IMG_Load(fileName);
    if(!tempSurface)
        std::cout << "ERROR LOAD IMAGE" << std::endl;
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
};

void TextureManager::draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}

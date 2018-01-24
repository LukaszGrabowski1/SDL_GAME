#ifndef Map_hpp
#define Map_hpp

#include <vector>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

class Map{
public:
    Map();
    ~Map();
    
    void loadMap(int map[20][25]);
    void drawMap();
    std::vector<SDL_Rect> getWalls(){return walls;};
    std::vector<SDL_Rect> getFinishes(){return finishes;};
private:
    SDL_Rect src, dest;
    SDL_Texture* wall;
    SDL_Texture* finish;
    
    std::vector<SDL_Rect> walls;
    std::vector<SDL_Rect> finishes;
    
    int map[20][25];
};
#endif /* Map_hpp */

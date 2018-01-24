#ifndef Game_hpp
#define Game_hpp

#include "Map.hpp"
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <iostream>
class Game{
public:
    Game();
    ~Game();
    
    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning;}
    void stopGame() {isRunning = false;}
    bool isWon() {return win;}
    void gameWon() {win = true;}
    static SDL_Renderer *renderer;
    Map *mapToDisplay;
    
private:
    int cnt;
    bool isRunning;
    bool win;
    SDL_Window *window;
};
#endif /* Game_hpp */



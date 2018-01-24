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
    void startGame() {isRunning = true;}
    bool isWon() {return win;}
    bool isLose() {return lose;}
    void gameWon() {win = true; lose = false;}
    void gameLose() {win = false; lose = true;}
    static SDL_Renderer *renderer;
    Map *mapToDisplay;
    bool initalScreen;
    
private:
    int cnt;
    bool isRunning;
    bool win;
    bool lose;
    SDL_Window *window;
};
#endif /* Game_hpp */



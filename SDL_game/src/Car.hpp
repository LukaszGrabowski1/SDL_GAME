#ifndef Car_hpp
#define Car_hpp

#include "Game.hpp"
class Car{
public:
    Car(const char* file);
    ~Car();
    void handleEvents();
    void update();
    void render();
    float x, y;
    float gdx, gdy;
    float dx, dy;
    
private:
    float ang;
    SDL_Texture *objTexture;
    SDL_Rect srcR, destR;
};

#endif /* Car_hpp */

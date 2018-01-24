#include "Game.hpp"
#include "Car.hpp"
#include "Map.hpp"
#include "Background.hpp"
#include "TextureManager.hpp"
#include "Global.hpp"
#include "Collision.hpp"


SDL_Renderer * Game::renderer = nullptr;
Car *car = nullptr;
Background *background = nullptr;
Collision *collision = nullptr;
SDL_Texture *winTexture = nullptr;
Game::Game(){
    
}

Game::~Game(){
    
}

void Game::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Initialised" << std::endl;
        
        window = SDL_CreateWindow("Moja gra", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        
        if(window)
            std::cout << "Window created" << std::endl;
        
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;
    }else
        isRunning = false;
    
    car = new Car("assets/car.png");
    background = new Background("assets/bg.jpg");
    collision = new Collision();
    mapToDisplay = new Map();
    
    winTexture = TextureManager::loadTexture("assets/winner.jpg");
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_WINDOWEVENT_CLOSE:
                isRunning = false;
                break;
            case SDL_KEYDOWN:{
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break;
                }
            }
                break;
            default:
                break;
        }
    }
    if(!isWon())
        car->handleEvents();
}

void Game::update(){
    
    if(!isWon()){
        collision->detectCollision(this, car);
        car->update();
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    if(isWon()){
        SDL_Rect dest;
        dest.w = 576;
        dest.h = 640;
        dest.x = 115;
        dest.y = 0;
        SDL_RenderCopy(Game::renderer, winTexture, NULL, &dest);
    }else{
        background->render();
        mapToDisplay->drawMap();
        car->render();
    }
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}

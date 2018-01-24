#include "Game.hpp"
#include "Car.hpp"
#include "Map.hpp"
#include "Background.hpp"
#include "TextureManager.hpp"
#include "Global.hpp"
#include "Collision.hpp"
#include "Button.h"


SDL_Renderer * Game::renderer = nullptr;
Car *car = nullptr;
Background *mapBackground = nullptr;
Background *homeBackground = nullptr;
Collision *collision = nullptr;
SDL_Texture *winTexture = nullptr;
SDL_Texture *loseTexture = nullptr;
Button *startBtn = nullptr;
Button *quitBtn = nullptr;

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
    
    
    initalScreen = true;
    startBtn = new Button( 140, 460, 180, 50 );
    quitBtn = new Button( 510, 460, 180, 50 );
    
    
    if( (startBtn->load_files("assets/startbut.png") == false) or (quitBtn->load_files("assets/quitbut.png") == false))
        stopGame();
    startBtn->set_clips();
    quitBtn->set_clips();
    
    car = new Car("assets/car.png");
    mapBackground = new Background("assets/bg.jpg");
    homeBackground = new Background("assets/home.jpg");
    collision = new Collision();
    mapToDisplay = new Map();
    
    winTexture = TextureManager::loadTexture("assets/winner.jpg");
    loseTexture = TextureManager::loadTexture("assets/game_over.jpg");
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
        
        if(initalScreen){
            startBtn->handle_events(&event);
            quitBtn->handle_events(&event);
        }
    }
    
    if(!isWon() and !initalScreen)
        car->handleEvents();
}

void Game::update(){
    
    if(!isWon() and !initalScreen){
        collision->detectCollision(this, car);
        car->update();
    }
    if(quitBtn->buttonclick == true){
        Game::stopGame();
    }
    if(startBtn->buttonclick == true){
        initalScreen = false;
    }
    
}

void Game::render()
{
    SDL_RenderClear(renderer);
    if(initalScreen){
        homeBackground->render();
        startBtn->showButton();
        quitBtn->showButton();
    }
    else{
        if(isWon()){
            SDL_RenderCopy(Game::renderer, winTexture, NULL, NULL);
        }else if(isLose()){
            SDL_RenderCopy(Game::renderer, loseTexture, NULL, NULL);
        }else{
        mapBackground->render();
        mapToDisplay->drawMap();
        car->render();
    }
    }
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}

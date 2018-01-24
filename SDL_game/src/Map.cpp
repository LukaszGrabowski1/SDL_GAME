#include "Map.hpp"
#include "TextureManager.hpp"
#include "iostream"
#include <fstream>
#include "Global.hpp"



Map::Map()
{
    wall = TextureManager::loadTexture("assets/wall.jpg");
    finish = TextureManager::loadTexture("assets/finish.png");
    
    
    
    std::ifstream plik("assets/map.txt");
    for(int row = 0; row < 20; row++)
        for(int column = 0; column < 25; column++){
            plik >> map[row][column];
            dest.x = column*TILE_HEIGHT;
            dest.y = row*TILE_WIDTH;
            dest.w = TILE_WIDTH;
            dest.h = TILE_HEIGHT;
            switch (map[row][column]) {
                case 1:
                    walls.push_back(dest);
                    break;
                case 2:
                    finishes.push_back(dest);
                    break;
            }
        }
    src.w = TILE_WIDTH;
    src.h = TILE_WIDTH;
}

Map::~Map(){};

void Map::loadMap(int arr[20][25]){
    for(int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){
            map[row][column] = arr[row][column];
        }
    }
}

void Map::drawMap(){
    int type;
    
    for(int row = 0; row < 20; row++){
        for(int column = 0; column < 25; column++){
            type = map[row][column];
            
            dest.x = column*TILE_HEIGHT;
            dest.y = row*TILE_WIDTH;
            
            switch (type) {
                case 1:
                    TextureManager::draw(wall, src, dest);
                    break;
                case 2:
                    TextureManager::draw(finish, src, dest);
                    break;
                    
                default:
                    break;
            }
            }
        }
}


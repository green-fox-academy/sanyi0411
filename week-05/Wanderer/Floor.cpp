//
// Created by sando on 2019. 04. 29..
//

#include "Floor.h"
#include <ctime>

SDL_Texture *texture = nullptr;

Floor::Floor() {

}

void Floor::loadSurface(SDL_Renderer *renderer, int screenSize)
{
    SDL_Surface *floorSurface = IMG_Load("../img/floor.png");
    if (floorSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    SDL_Texture *floorTexture = nullptr;
    floorTexture = SDL_CreateTextureFromSurface(renderer, floorSurface);
    SDL_FreeSurface(floorSurface);

    SDL_Surface *wallSurface = IMG_Load("../img/wall.png");
    if (floorSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    SDL_Texture *wallTexture = nullptr;
    wallTexture = SDL_CreateTextureFromSurface(renderer, wallSurface);
    SDL_FreeSurface(floorSurface);


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (maze[j][i] == 1) {
                SDL_Rect dstrect = {i * screenSize / 10, j * screenSize / 10, screenSize / 10, screenSize / 10};
                SDL_RenderCopy(renderer, floorTexture, NULL, &dstrect);
                SDL_RenderPresent(renderer);
            } else {
                SDL_Rect dstrect = {i * screenSize / 10, j * screenSize / 10, screenSize / 10, screenSize / 10};
                SDL_RenderCopy(renderer, wallTexture, NULL, &dstrect);
                SDL_RenderPresent(renderer);
            }
        }
    }
}
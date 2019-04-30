//
// Created by sando on 2019. 04. 29..
//

#include "Hero.h"

Hero::Hero()
{
    _xOfCharacter = 0;
    _yOfCharacter = 0;
}

void Hero::loadHero(SDL_Renderer *renderer, int screenSize, int x, int y)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/hero-down.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);


    SDL_Rect dstrect = {x * screenSize / 10, y * screenSize / 10, screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);
}

void Hero::deleteHero(SDL_Renderer *renderer, int screenSize, int x, int y)
{
    SDL_Surface *floorSurface = IMG_Load("../img/floor.png");
    if (floorSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    SDL_Texture *floorTexture = nullptr;
    floorTexture = SDL_CreateTextureFromSurface(renderer, floorSurface);
    SDL_FreeSurface(floorSurface);

    SDL_Rect dstrect = {x * screenSize / 10, y * screenSize / 10, screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, floorTexture, NULL, &dstrect);
    SDL_RenderPresent(renderer);
}

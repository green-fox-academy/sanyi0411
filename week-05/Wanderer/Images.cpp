//
// Created by sando on 2019. 04. 29..
//

#include "Images.h"
#include <ctime>

SDL_Texture *texture = nullptr;

Images::Images()
{}

int maze [10][10] = {{1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                     {1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
                     {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                     {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                     {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                     {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
                     {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
                     {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                     {1, 1, 1, 0, 1, 0, 0, 1, 0, 1}};

void Images::loadSurface(SDL_Renderer *renderer, int screenSize)
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

void Images::loadHero(SDL_Renderer *renderer, int screenSize)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/hero-down.png"); //path is the string that contains where the image is
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    //SDL_Renderer* object
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);


    SDL_Rect dstrect = {0, 0, screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);
}

std::pair<int, int> Images::loadBoss(SDL_Renderer *renderer, int screenSize)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/boss.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    //SDL_Renderer* object
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    Images ob1;

    std::pair<int, int> randomCoord = ob1.randomCoordinates();

    SDL_Rect dstrect = {randomCoord.first * (screenSize / 10), randomCoord.second * (screenSize / 10), screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    return randomCoord;
}

void Images::loadSkeleton(SDL_Renderer *renderer, int screenSize, int numberOfSkeletons, std::pair<int, int> pair)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/skeleton.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    //SDL_Renderer* object
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    Images ob1;

    int skeletons = 0;
    while (skeletons < numberOfSkeletons) {
        base:
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;

        if (maze[y][x] != 1) {
            goto base;
        }

        if (pair.first != x && pair.second != y) {
            SDL_Rect dstrect = {x * (screenSize / 10), y * (screenSize / 10), screenSize / 10, screenSize / 10};
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);
        }

        skeletons++;
    }

}

std::pair<int, int> Images::randomCoordinates()
{
    srand(time(NULL));

    int x = rand() % 9 + 1;
    int y = rand() % 9 + 1;
    while (maze[y][x] != 1) {
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
    }

    return std::make_pair(x, y);
}
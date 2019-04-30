//
// Created by sando on 2019. 04. 30..
//

#include "Enemy.h"

Floor floor;

std::pair<int, int> Enemy::loadBoss(SDL_Renderer *renderer, int screenSize)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/boss.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    //SDL_Renderer* object
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    Enemy ob1;

    std::pair<int, int> randomCoord = ob1.randomCoordinates();

    SDL_Rect dstrect = {randomCoord.first * (screenSize / 10), randomCoord.second * (screenSize / 10), screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    return randomCoord;
}

void Enemy::loadSkeleton(SDL_Renderer *renderer, int screenSize, int numberOfSkeletons, std::pair<int, int> bossPosition)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/skeleton.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    //SDL_Renderer* object
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    Enemy ob1;

    int skeletons = 0;
    int previousX = 0;
    int previousY = 0;
    while (skeletons < numberOfSkeletons) {
        int x;
        int y;
        do {
            x = rand() % 9 + 1;
            y = rand() % 9 + 1;
        } while (floor.maze[y][x] != 1);
        if (bossPosition.first != x && bossPosition.second != y && previousX != x && previousY != y) {
            SDL_Rect dstrect = {x * (screenSize / 10), y * (screenSize / 10), screenSize / 10, screenSize / 10};
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);
            previousX = x;
            previousY = y;
            skeletons++;
        }
    }
}

std::pair<int, int> Enemy::randomCoordinates()
{
    int x = rand() % 9 + 1;
    int y = rand() % 9 + 1;
    while (floor.maze[y][x] != 1) {
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
    }

    return std::make_pair(x, y);
}
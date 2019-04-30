//
// Created by sando on 2019. 04. 30..
//

#include "Enemy.h"

Floor floor2;

void Enemy::loadBoss(SDL_Renderer *renderer, int screenSize)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/boss.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    //SDL_Renderer* object
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    int x;
    int y;
    do {
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
    } while (floor2._maze[y][x] != 1);

    SDL_Rect dstrect = {x * (screenSize / 10), y * (screenSize / 10), screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    floor2._occupied[y][x] = 2;
}

void Enemy::loadSkeletonWithoutKey(SDL_Renderer *renderer, int screenSize, int numberOfSkeletons)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/skeleton.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    Enemy ob1;

    int skeletons = 0;
    while (skeletons < numberOfSkeletons) {
        int x;
        int y;
        do {
            x = rand() % 9 + 1;
            y = rand() % 9 + 1;
        } while (floor2._maze[y][x] != 1);
        if (floor2._occupied[y][x] == 0) {
            SDL_Rect dstrect = {x * (screenSize / 10), y * (screenSize / 10), screenSize / 10, screenSize / 10};
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
            SDL_RenderPresent(renderer);
            floor2._occupied[y][x] = 4;
            skeletons++;
        }
    }
}

void Enemy::loadSkeletenWithKey(SDL_Renderer *renderer, int screenSize)
{
    SDL_Surface *loadedSurface = IMG_Load("../img/skeleton.png");
    if (loadedSurface == nullptr) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
    }
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    int x;
    int y;
    do {
        x = rand() % 9 + 1;
        y = rand() % 9 + 1;
    } while (floor2._maze[y][x] != 1);

    SDL_Rect dstrect = {x * (screenSize / 10), y * (screenSize / 10), screenSize / 10, screenSize / 10};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);

    floor2._occupied[y][x] = 3;
}
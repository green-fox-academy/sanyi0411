//
// Created by sando on 2019. 04. 30..
//

#ifndef WANDERER_ENEMY_H
#define WANDERER_ENEMY_H

#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include "Character.h"
#include "Floor.h"


class Enemy : public Character {
public:
    void loadBoss(SDL_Renderer *renderer, int screenSize);
    void loadSkeletonWithoutKey(SDL_Renderer *renderer, int screenSize, int numberOfSkeletons);
    void loadSkeletenWithKey(SDL_Renderer *renderer, int screenSize);

private:
    SDL_Texture *texture = nullptr;

};


#endif //WANDERER_ENEMY_H

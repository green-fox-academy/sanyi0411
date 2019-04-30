//
// Created by sando on 2019. 04. 29..
//

#ifndef WANDERER_HERO_H
#define WANDERER_HERO_H
#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Character.h"

class Hero : public Character {
public:
    Hero();

    void loadHero(SDL_Renderer *renderer, int screenSize, int x, int y);
    void deleteHero(SDL_Renderer *renderer, int screenSize, int x, int y);
private:
    SDL_Texture *texture = nullptr;
    SDL_Renderer *gRenderer = nullptr;

};


#endif //WANDERER_HERO_H

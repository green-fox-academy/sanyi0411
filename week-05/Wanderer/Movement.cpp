//
// Created by sando on 2019. 04. 29..
//

#include "Movement.h"

Movement::Movement() {}

SDL_Renderer *grenderer = nullptr;

void Movement::moveHeroRight()
{
    _xOfHero++;
    loadHero(grenderer, 800, _xOfHero, _yOfHero);
}
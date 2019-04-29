//
// Created by sando on 2019. 04. 29..
//

#ifndef WANDERER_MOVEMENT_H
#define WANDERER_MOVEMENT_H

#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Images.h"

class Movement : public Images {
public:
    Movement();

    void moveHeroRight();
private:
    int _xOfHero = 0;
    int _yOfHero = 0;

};


#endif //WANDERER_MOVEMENT_H

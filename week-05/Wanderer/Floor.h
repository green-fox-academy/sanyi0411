//
// Created by sando on 2019. 04. 29..
//

#ifndef WANDERER_FLOOR_H
#define WANDERER_FLOOR_H

#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <vector>


class Floor {
public:
    Floor();

    void loadSurface(SDL_Renderer *renderer, int screenSize);

    int maze [10][10] = {
            {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
            {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 0, 1, 0, 0, 1, 1, 1}
    };
private:

};


#endif //WANDERER_FLOOR_H

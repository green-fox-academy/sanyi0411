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

    int _maze [10][10] = {
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

    int _occupied [10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                    //0 - not occupied
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                    //1 - Hero
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                    //2 - Boss
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                    //3 - Skeleton with key
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                    //4 - Skeleton without key
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

private:

};


#endif //WANDERER_FLOOR_H

//
// Created by sando on 2019. 04. 29..
//

#ifndef WANDERER_IMAGES_H
#define WANDERER_IMAGES_H

#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <vector>


class Images {
public:
    Images();
    void loadSurface(SDL_Renderer *renderer, int screenSize);
    void loadHero(SDL_Renderer *renderer, int screenSize);
    std::pair<int, int> loadBoss(SDL_Renderer *renderer, int screenSize);
    void loadSkeleton(SDL_Renderer *renderer, int screenSize, int numberOfSkeletons, std::pair<int, int> pair);
    std::pair<int, int> randomCoordinates();
};


#endif //WANDERER_IMAGES_H

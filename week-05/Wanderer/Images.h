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

    int getXOfHero() const;
    int getYOfHero() const;

    void setXOfHero(int xOfHero);
    void setYOfHero(int yOfHero);

    void loadSurface(SDL_Renderer *renderer, int screenSize);
    void loadHero(SDL_Renderer *renderer, int screenSize, int x, int y);
    std::pair<int, int> loadBoss(SDL_Renderer *renderer, int screenSize);
    void loadSkeleton(SDL_Renderer *renderer, int screenSize, int numberOfSkeletons, std::pair<int, int> pair);
    std::pair<int, int> randomCoordinates();

private:
    int _xOfHero;
    int _yOfHero;
};


#endif //WANDERER_IMAGES_H

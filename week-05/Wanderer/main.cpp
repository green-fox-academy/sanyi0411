#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Floor.h"
#include "Hero.h"
#include "Enemy.h"

//Screen dimension constants
const int SCREEN_SIZE = 800;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Wanderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_SIZE,
                               SCREEN_SIZE, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        SDL_Log("Window could not be created! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        SDL_Log("Renderer could not be created! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Initialize PNG loading
    IMG_Init(IMG_INIT_PNG);
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    IMG_Quit();

    SDL_Quit();
}

int main(int argc, char *args[])
{
    srand(time(NULL));

    //Start up SDL and create window
    if (!init()) {
        SDL_Log("Failed to initialize!");
        close();
        return -1;
    }

    Floor floor;
    Hero hero;
    Enemy enemies;

    floor.loadSurface(gRenderer, SCREEN_SIZE);
    hero.loadHero(gRenderer, SCREEN_SIZE, 0, 0);
    enemies.loadSkeleton(gRenderer, SCREEN_SIZE, 2, enemies.loadBoss(gRenderer, SCREEN_SIZE));

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        if (hero.getYOfCharacter() > 0 && floor.maze[hero.getYOfCharacter() - 1][hero.getXOfCharacter()] == 1) {
                            hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                            hero.setYOfCharacter(hero.getYOfCharacter() - 1);
                            hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                        }
                        break;
                    case SDLK_DOWN:
                        if (hero.getYOfCharacter() < 9 && floor.maze[hero.getYOfCharacter() + 1][hero.getXOfCharacter()] == 1) {
                            hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                            hero.setYOfCharacter(hero.getYOfCharacter() + 1);
                            hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                        }
                        break;
                    case SDLK_LEFT:
                        if (hero.getXOfCharacter() > 0 && floor.maze[hero.getYOfCharacter()][hero.getXOfCharacter() - 1] == 1) {
                            hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                            hero.setXOfCharacter(hero.getXOfCharacter() - 1);
                            hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                        }
                        break;
                    case SDLK_RIGHT:
                        if (hero.getXOfCharacter() < 9 && floor.maze[hero.getYOfCharacter()][hero.getXOfCharacter() + 1] == 1) {
                            hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                            hero.setXOfCharacter(hero.getXOfCharacter() + 1);
                            hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(), hero.getYOfCharacter());
                        }
                        break;
                }
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        //SDL_RenderClear(gRenderer);

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
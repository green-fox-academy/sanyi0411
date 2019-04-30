#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Hero.h"
#include "Enemy.h"
#include "LTexture.h"

//Screen dimension constants
const int SCREEN_SIZE = 800;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The surface contained by the window
SDL_Surface *gScreenSurface = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;

//Rendered texture
LTexture gTextTexture;

//Globally used font
TTF_Font *gFont = nullptr;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL Error: %s", SDL_GetError());
        success = false;
    } else {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow("Wanderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_SIZE,
                                   SCREEN_SIZE * 1.1, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            SDL_Log("Window could not be created! SDL Error: %s", SDL_GetError());
            success = false;
        } else {

            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == nullptr) {
                SDL_Log("Renderer could not be created! SDL Error: %s", SDL_GetError());
                success = false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                IMG_Init(IMG_INIT_PNG);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    SDL_Log("Image could not be loaded! SDL Error: %s", SDL_GetError());
                    success = false;
                }

                //Initialize SDL_ttf
                if(TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Open the font
    gFont = TTF_OpenFont("../lazy.ttf", 28);
    if(gFont == nullptr)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        if( !gTextTexture.loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor, gRenderer))
        {
            printf("Failed to render text texture!\n");
            success = false;
        }
    }

    return success;
}

void close()
{
    //Free loaded images
    gTextTexture.free();

    //Free global font
    TTF_CloseFont(gFont);
    gFont = nullptr;

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
    srand(time(nullptr));

    //Start up SDL and create window
    if (!init()) {
        SDL_Log("Failed to initialize!");
        close();
        return -1;
    } else {
        //Load media
        if (!loadMedia()) {
            SDL_Log("Failed to load media!\n");
        } else {
            Floor floor;
            Hero hero;
            Enemy enemies;

            floor.loadSurface(gRenderer, SCREEN_SIZE);
            hero.loadHero(gRenderer, SCREEN_SIZE, 0, 0, "../img/hero-down.png");
            enemies.loadBoss(gRenderer, SCREEN_SIZE);
            enemies.loadSkeletonWithoutKey(gRenderer, SCREEN_SIZE, 2);
            enemies.loadSkeletenWithKey(gRenderer, SCREEN_SIZE);

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
                                if (hero.getYOfCharacter() > 0 && floor._maze[hero.getYOfCharacter() - 1][hero.getXOfCharacter()] == 1) {
                                    hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                    hero.getYOfCharacter());
                                    hero.setYOfCharacter(hero.getYOfCharacter() - 1);
                                    hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                  hero.getYOfCharacter(), "../img/hero-up.png");
                                }
                                break;
                            case SDLK_DOWN:
                                if (hero.getYOfCharacter() < 9 && floor._maze[hero.getYOfCharacter() + 1][hero.getXOfCharacter()] == 1) {
                                    hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                    hero.getYOfCharacter());
                                    hero.setYOfCharacter(hero.getYOfCharacter() + 1);
                                    hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                  hero.getYOfCharacter(), "../img/hero-down.png");
                                }
                                break;
                            case SDLK_LEFT:
                                if (hero.getXOfCharacter() > 0 && floor._maze[hero.getYOfCharacter()][hero.getXOfCharacter() - 1] == 1) {
                                    hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                    hero.getYOfCharacter());
                                    hero.setXOfCharacter(hero.getXOfCharacter() - 1);
                                    hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                  hero.getYOfCharacter(), "../img/hero-left.png");
                                }
                                break;
                            case SDLK_RIGHT:
                                if (hero.getXOfCharacter() < 9 && floor._maze[hero.getYOfCharacter()][hero.getXOfCharacter() + 1] == 1) {
                                    hero.deleteHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                    hero.getYOfCharacter());
                                    hero.setXOfCharacter(hero.getXOfCharacter() + 1);
                                    hero.loadHero(gRenderer, SCREEN_SIZE, hero.getXOfCharacter(),
                                                  hero.getYOfCharacter(), "../img/hero-right.png");
                                }
                                break;
                        }
                    }
                }
            }
        }



        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        //SDL_RenderClear(gRenderer);

        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

        //Render current frame
        gTextTexture.render((SCREEN_SIZE - gTextTexture.getWidth()) / 2, (SCREEN_SIZE - gTextTexture.getHeight()) / 2);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
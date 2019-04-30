//
// Created by sando on 2019. 04. 30..
//

#ifndef WANDERER_LTEXTURE_H
#define WANDERER_LTEXTURE_H

#include <iostream>
#include <SDL.h>
#include <SDL_log.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

//Globally used font
extern TTF_Font *gFont;

class LTexture {
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Creates image from font string
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer *renderer);

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, SDL_Renderer *renderer = nullptr );

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //WANDERER_LTEXTURE_H

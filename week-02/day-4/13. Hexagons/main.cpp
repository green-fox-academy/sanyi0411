#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void hexagon_fractal(int x, int y, int size)
{
    if (size < 15) {
        return;
    }
    SDL_SetRenderDrawColor(gRenderer, 000, 000, 000, 255);

    SDL_RenderDrawLine(gRenderer, x+size/4, y, x+3*size/4, y);              //top line
    SDL_RenderDrawLine(gRenderer, x+3*size/4, y, x+size, y+size/2);         //top right line
    SDL_RenderDrawLine(gRenderer, x+size, y+size/2, x+3*size/4, y+size);    //bottom right line
    SDL_RenderDrawLine(gRenderer, x+3*size/4, y+size, x+size/4, y+size);    //bottom line
    SDL_RenderDrawLine(gRenderer, x+size/4, y+size, x, y+size/2);           //bottom left line
    SDL_RenderDrawLine(gRenderer, x, y+size/2, x+size/4, y);                //top left line

    hexagon_fractal(x+size/8, y, size/2);                               //top hexagon
    hexagon_fractal(x+size/2, y+size/4, size/2);                            //middle hexagon
    hexagon_fractal(x+size/8, y+size/2, size/2);                        //bottom hexagon

    /*
    SDL_RenderDrawLine(gRenderer, x-size/4, y-size/2, x+size/4, y-size/2);  //top line
    SDL_RenderDrawLine(gRenderer, x+size/4, y-size/2, x+size/2, y);         //top right line
    SDL_RenderDrawLine(gRenderer, x+size/2, y, x+size/4, y+size);           //bottom right line
    SDL_RenderDrawLine(gRenderer, x+size/4, y+size, x-size/4, y+size);      //bottom line
    SDL_RenderDrawLine(gRenderer, x-size/4, y+size, x-size/2, y);           //bottom left line
    SDL_RenderDrawLine(gRenderer, x-size/2, y, x-size/4, y-size/2);         //top left line

    hexagon_fractal(x-size/4, y+size/2, size/2);
    hexagon_fractal(x+size/4, y, size/2);
    hexagon_fractal(x-size/4, y+size/2, size/2);
     */
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Horizontal lines", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        hexagon_fractal(0, 0, SCREEN_WIDTH);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
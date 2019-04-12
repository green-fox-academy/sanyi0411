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

void triangles_fractal(int x, int y, int size)
{
    if (size < 10){
        return;
    }
    SDL_SetRenderDrawColor(gRenderer, 000, 000, 000, 255);

    SDL_RenderDrawLine(gRenderer, x, y, x+size, y);
    SDL_RenderDrawLine(gRenderer, x+size, y, x+size/2, y+size);
    SDL_RenderDrawLine(gRenderer, x+size/2, y+size, x, y);

    SDL_RenderDrawLine(gRenderer, x+size/2, y, x+3*size/4, y+size/2);
    SDL_RenderDrawLine(gRenderer, x+3*size/4, y+size/2, x+size/4, y+size/2);
    SDL_RenderDrawLine(gRenderer, x+size/4, y+size/2, x+size/2, y);

    triangles_fractal(x, y, size/2);
    triangles_fractal(x+size/2, y, size/2);
    triangles_fractal(x+size/4, y+size/2, size/2);

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

        triangles_fractal(0, 0, SCREEN_WIDTH);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
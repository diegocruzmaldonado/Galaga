#include<SDL2/SDL.h>
#include<iostream>

int main(int argc, char *argv[])
{
    // Initializing and loading variables
    SDL_Window *window = nullptr;
    SDL_Surface *windowSurface = nullptr;
    SDL_Surface *image1 = nullptr;
    SDL_Surface *image2 = nullptr;
    SDL_Surface *image3 = nullptr;
    SDL_Surface *currentImage = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Galaga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    windowSurface = SDL_GetWindowSurface(window);
    
    image1 = SDL_LoadBMP("background.bmp");
    image2 = SDL_LoadBMP("start.bmp");
    image3 = SDL_LoadBMP("credits.bmp");
    
    currentImage = image1;
    
    bool isRunning = true;
    SDL_Event ev;
    
    while(isRunning)
    {
        while(SDL_PollEvent(&ev) != 0)
        {
            // Getting the quit and the keyboard events
            if(ev.type == SDL_QUIT)
                isRunning = false;
            else if(ev.type == SDL_MOUSEBUTTONUP) //SDL_MOUSEMOTION
            {
                if(ev.button.clicks == 1) //.x or .y < a number
                {
                    currentImage = image2;
                }
                else if(ev.button.clicks == 2) //.x or .y < a number
                {
                    currentImage = image3;
                }
                else
                    currentImage = image1;
            }
        }
        
        // Drawing the current image to the window
        SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface(window);
    }
    
    // Freeing the memory
    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
    SDL_DestroyWindow(window);
    
    image1 = image2 = image3 = windowSurface = nullptr;
    window = nullptr;
    
    SDL_Quit();
    
    return 0;
}

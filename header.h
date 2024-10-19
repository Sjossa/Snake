#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdarg.h>

#define MAX_SEGMENTS 100

typedef struct {
    SDL_Window* window;  
    SDL_Event *event;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Texture* texture2;
    SDL_Texture* texture3;
    SDL_Texture* texture4;

    int X;
    int Y;
    int width;
    int height; 
    int cerise;
} context;

void evenement();
void position();
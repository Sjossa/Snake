#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdarg.h>


typedef struct{
  SDL_Window* window;  
  SDL_Event * event;
  SDL_Renderer* renderer;
  SDL_Surface* surface;
  SDL_Texture* texture;
  int width;
  int height; 
}context;

void evenement();
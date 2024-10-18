#include "header.h"

void image(SDL_Rect *destRect, context *w) {
    SDL_Delay(30);
    // Rendu de l'image
    SDL_RenderClear(w->renderer);
    SDL_RenderCopy(w->renderer, w->texture, NULL, destRect);
    SDL_RenderPresent(w->renderer);
}

void evenement(SDL_Rect *destRect, context *w) { 
    SDL_Event event;
    int keys[SDL_NUM_SCANCODES] = {0}; 
    int direction = 0; 
    int block =0;

    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return; 
            }

            if (event.type == SDL_KEYDOWN) {
                
                if (event.key.keysym.scancode == SDL_SCANCODE_Z || event.key.keysym.scancode == SDL_SCANCODE_W) {
                    direction = 1; // Monter
                } 
                else if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    direction = 2; // Descendre
                } 
                else if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    direction = 3; // Droite
                } 
                else if (event.key.keysym.scancode == SDL_SCANCODE_Q || event.key.keysym.scancode == SDL_SCANCODE_A) {
                    direction = 4; // Gauche
                }else if ()
            }

            
            if (event.type == SDL_KEYUP) {
                
                if (event.key.keysym.scancode == SDL_SCANCODE_Z || event.key.keysym.scancode == SDL_SCANCODE_W ||
                    event.key.keysym.scancode == SDL_SCANCODE_S ||
                    event.key.keysym.scancode == SDL_SCANCODE_D ||
                    event.key.keysym.scancode == SDL_SCANCODE_Q || event.key.keysym.scancode == SDL_SCANCODE_A) {
                    
                }
            }
        }

        
        switch (direction) {
            case 1: 
                if (destRect->y > 0) {
                    destRect->y--;
                }
                break;
            case 2: 
                if (destRect->y < w->height - 20) {
                    destRect->y++;
                }
                break;
            case 3: 
                if (destRect->x < w->width - 20) {
                    destRect->x++;
                }
                break;
            case 4: 
                if (destRect->x > 0) {
                    destRect->x--;
                }
                break;
            default:
                break; 
        }

        
        image(destRect, w);
    }
}








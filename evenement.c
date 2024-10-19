#include "header.h"

void image(SDL_Rect *destRects, SDL_Rect destRects2, int segment, context *w) { 
    SDL_RenderClear(w->renderer);
    SDL_Rect bgRect = {0, 0, w->width, w->height}; 
    SDL_RenderCopy(w->renderer, w->texture4, NULL, &bgRect);

    SDL_Rect topWall = {0, 0, w->width, 20};   
    SDL_Rect bottomWall = {0, w->height - 20, w->width, 20}; 
    SDL_Rect leftWall = {0, 0, 25, w->height};  
    SDL_Rect rightWall = {w->width - 20, 0, 20, w->height}; 

    SDL_RenderCopy(w->renderer, w->texture3, NULL, &topWall);
    SDL_RenderCopy(w->renderer, w->texture3, NULL, &bottomWall);
    SDL_RenderCopy(w->renderer, w->texture3, NULL, &leftWall);
    SDL_RenderCopy(w->renderer, w->texture3, NULL, &rightWall);

    SDL_RenderCopy(w->renderer, w->texture2, NULL, &destRects2);
    
    for (int i = 0; i < segment; i++) {
        SDL_RenderCopy(w->renderer, w->texture, NULL, &destRects[i]);
    }

    SDL_RenderPresent(w->renderer);
}

void evenement(SDL_Rect *destRects, SDL_Rect destRects2, context *w) { 
    SDL_Event event;
    int direction = 0; 
    int segment = 4; 
    int cerise = 0;

    position(&destRects2, destRects, segment, w); 

    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return; 
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_Z || event.key.keysym.scancode == SDL_SCANCODE_W) {
                    direction = 1;  
                } else if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    direction = 2;  
                } else if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    direction = 3;  
                } else if (event.key.keysym.scancode == SDL_SCANCODE_Q || event.key.keysym.scancode == SDL_SCANCODE_A) {
                    direction = 4;  
                }
            }
        }

        for (int i = segment - 1; i > 0; i--) { 
            destRects[i] = destRects[i - 1]; 
        }

        switch (direction) {
            case 1: 
                if (destRects[0].y > 0) {
                    destRects[0].y -= destRects[0].h;  
                }
                break;
            case 2: 
                if (destRects[0].y < w->height - destRects[0].h) {
                    destRects[0].y += destRects[0].h;  
                }
                break;
            case 3: 
                if (destRects[0].x < w->width - destRects[0].w) {
                    destRects[0].x += destRects[0].w;  
                }
                break;
            case 4: 
                if (destRects[0].x > 0) {
                    destRects[0].x -= destRects[0].w;  
                }
                break;
            default:
                break; 
        }

        if (SDL_HasIntersection(&destRects[0], &destRects2)) {
            cerise++;
            segment++;  
            printf("Cerise mangée ! Total : %d\n", cerise);
            position(&destRects2, destRects, segment, w); 
        }

        if (destRects[0].x < 0 || destRects[0].x + destRects[0].w > w->width || destRects[0].y < 0 || destRects[0].y + destRects[0].h > w->height) {
            printf("Perdu ! Vous avez touché un mur.\n");
            return; 
        }

        image(destRects, destRects2, segment, w);
        SDL_Delay(150);
    }
}

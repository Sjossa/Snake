#include "header.h"

int main() {

int width = 640;
int height = 480;

    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        printf("Error SDL2 Init : %s\n", SDL_GetError());
        return 1;
    }


    context w;
    w.window = SDL_CreateWindow("ma", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (w.window == NULL) {
        printf("Erreur de création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialiser SDL_image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Erreur d'initialisation de la SDL_Image\n");
        SDL_DestroyWindow(w.window);
        SDL_Quit();
        return 1;
    }

    // Créer le renderer
    w.renderer = SDL_CreateRenderer(w.window, -1, SDL_RENDERER_ACCELERATED);
    if (w.renderer == NULL) {
        printf("Erreur à la création du renderer\n");
        IMG_Quit();
        SDL_DestroyWindow(w.window);
        SDL_Quit();
        return 1;
    }

    // Charger l'image
    w.surface = IMG_Load("picture/snake.png");
    if (w.surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    
    w.texture = SDL_CreateTextureFromSurface(w.renderer, w.surface);
    SDL_FreeSurface(w.surface); 

    if (w.texture == NULL) {
        printf("Error creating texture\n");
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    

     SDL_Rect destRect;
    destRect.x = 72;  
    destRect.y = 72;  
    destRect.w = 16;  
    destRect.h = 16;


   w.width = width; 
   w.height = height; 

    

    SDL_RenderClear(w.renderer); 
            SDL_RenderCopy(w.renderer, w.texture, NULL, &destRect); 
            SDL_RenderPresent(w.renderer); 



    evenement(&destRect, &w);

    
    

    
    SDL_DestroyTexture(w.texture); 
    SDL_DestroyRenderer(w.renderer); 
    SDL_DestroyWindow(w.window); 
    IMG_Quit(); 
    SDL_Quit(); 

    return 0;
}

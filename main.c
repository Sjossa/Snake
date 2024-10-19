#include "header.h"

int main() {
    int width = 640;
    int height = 640;

    srand(time(NULL)); 

    
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

    
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        printf("Erreur d'initialisation de la SDL_Image\n");
        SDL_DestroyWindow(w.window);
        SDL_Quit();
        return 1;
    }

    
    w.renderer = SDL_CreateRenderer(w.window, -1, SDL_RENDERER_ACCELERATED);
    if (w.renderer == NULL) {
        printf("Erreur à la création du renderer\n");
        IMG_Quit();
        SDL_DestroyWindow(w.window);
        SDL_Quit();
        return 1;
    }

    // Initialiser la taille de la fenêtre
    w.width = width; 
    w.height = height;

    
    w.surface = IMG_Load("picture/snake.png");
    if (w.surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }
    w.texture = SDL_CreateTextureFromSurface(w.renderer, w.surface);
    SDL_FreeSurface(w.surface); 
    if (w.texture == NULL) {
        printf("Error creating texture\n");
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }

    
    w.surface = IMG_Load("picture/brique.png");
    if (w.surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }
    w.texture3 = SDL_CreateTextureFromSurface(w.renderer, w.surface);
    SDL_FreeSurface(w.surface); 
    if (w.texture3 == NULL) {
        printf("Error creating texture for wall image\n");
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }

    
    w.surface = IMG_Load("picture/CODA.png");
    if (w.surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }
    w.texture4 = SDL_CreateTextureFromSurface(w.renderer, w.surface);
    SDL_FreeSurface(w.surface); 
    if (w.texture4 == NULL) {
        printf("Error creating texture for background image\n");
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }

    
    w.surface = IMG_Load("picture/peur.png");
    if (w.surface == NULL) {
        printf("Error loading image %s\n", IMG_GetError());
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }
    w.texture2 = SDL_CreateTextureFromSurface(w.renderer, w.surface);
    SDL_FreeSurface(w.surface);
    if (w.texture2 == NULL) {
        printf("Error creating texture for second image\n");
        SDL_DestroyRenderer(w.renderer);
        SDL_DestroyWindow(w.window);
        IMG_Quit();
        return 1;
    }

    SDL_Rect destRects[MAX_SEGMENTS]; 
    destRects[0].x = 70;  
    destRects[0].y = 70;  
    destRects[0].w = 25;  
    destRects[0].h = 25;  

    SDL_Rect destRects2;
    destRects2.w = 25;  
    destRects2.h = 25;

    
    position(&destRects2, destRects, &w);
    

    
    evenement(destRects, destRects2, &w);  

    
    SDL_DestroyTexture(w.texture);
    SDL_DestroyTexture(w.texture2); 
    SDL_DestroyRenderer(w.renderer); 
    SDL_DestroyWindow(w.window); 
    IMG_Quit(); 
    SDL_Quit(); 

    return 0;
}

#include "header.h"

int isCerisePositionValid(int x, int y, SDL_Rect *destRects, int segment, context *w) {
    if (x < 25 || x > w->width - 20 || y < 20 || y > w->height - 20) {
        return 0; // La position touche un mur
    }

    for (int i = 0; i < segment; i++) {
        if (destRects[i].x == x && destRects[i].y == y) {
            return 0; // La position touche un segment du serpent
        }
    }

    return 1; // Position valide
}

int canPlaceCherry(SDL_Rect *snakeSegments, int snakeLength, context *w) {
    for (int y = 20; y < w->height - 20; y += 10) { 
        for (int x = 25; x < w->width - 20; x += 10) { 
            if (isCerisePositionValid(x, y, snakeSegments, snakeLength, w)) {
                return 1; 
            }
        }
    }
    return 0; 
}

void position(SDL_Rect *destRects2, SDL_Rect *snakeSegments, int snakeLength, context *w) {
    int x, y;
    int validPosition = 0;

    while (!validPosition) {
        x = (rand() % (w->width / 10)) * 10; 
        y = (rand() % (w->height / 10)) * 10; 

        if (isCerisePositionValid(x, y, snakeSegments, snakeLength, w)) {
            destRects2->x = x;
            destRects2->y = y;
            validPosition = 1; 
        } else if (!canPlaceCherry(snakeSegments, snakeLength, w)) {
            printf("Vous avez gagné ! Toutes les cerises ont été mangées.\n");
            exit(0); 
        }
    }
}

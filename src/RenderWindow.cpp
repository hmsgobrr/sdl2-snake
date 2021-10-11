#include "RenderWindow.h"

#include "GameUtils.h"
#include "Game.h"

SDL_Texture* RenderWindow::loadTexture(const char* filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == NULL) LOG("Texture Load failed: " << SDL_GetError());

    return texture;
}

void RenderWindow::create(const char* title, int w, int h) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if (window == NULL) LOG("Window Init failed: " << SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_RenderSetScale(renderer, Game::tileScale, Game::tileScale);
}

void RenderWindow::drawLine(int x1, int y1, int x2, int y2, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
    SDL_SetRenderDrawColor(renderer, 11, 19, 43, 255);
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Sprite& sprite) {
    SDL_Rect dst = { (int)sprite.pos.x, (int)sprite.pos.y, 1, 1 };

    SDL_RenderCopy(renderer, sprite.tex, NULL, &dst);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

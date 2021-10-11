#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameUtils.h"
#include "Sprite.h"

class RenderWindow {
public:
    RenderWindow(): window(NULL), renderer(NULL) {}
    SDL_Texture* loadTexture(const char* filePath);
    void create(const char* title, int w, int h);
    void cleanUp();
    void clear();
    void render(Sprite& sprite);
    void drawLine(int x1, int y1, int x2, int y2, Color color);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif

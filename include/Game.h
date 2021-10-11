#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>

#include "RenderWindow.h"
#include "Sprite.h"

struct Game {
    static const int tileScale = 40;
	static const int sWidth = 17*tileScale;
    static const int sHeight = 15*tileScale;

    static RenderWindow window;

    static float dt;

    static V2 player;
    static std::vector<V2> body;
    static Direction playerDir;
    static bool canMove;

    static V2 food;

    static void init();
    static void update();
    static void draw();
    static void unload();
};

#endif
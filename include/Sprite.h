#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameUtils.h"

struct Sprite {
    void create(SDL_Texture* tex, V2 pos, float scale);
    V2 pos;
    SDL_Texture* tex;
    int texWidth;
    int texHeight;
    float scale;
};

#endif

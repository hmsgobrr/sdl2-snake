#include "Sprite.h"

void Sprite::create(SDL_Texture* tex, V2 pos, float scale) {
    this->tex = tex;
    this->pos = pos;
    this->scale = scale;
    SDL_QueryTexture(tex, NULL, NULL, &texWidth, &texHeight);
}

#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include <iostream>
#define LOG(x) std::cout << x << std::endl;

#include <stdlib.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct V2 {
    float x, y;
};

struct Color {
    int r, g, b, a;
};

enum Direction { UP, DOWN, LEFT, RIGHT };

namespace utils {
    inline float getTime() {
        return SDL_GetTicks()*0.001f;
    }

    inline int getRandom(int min, int max) {
        if (min > max) {
            int tmp = max;
            max = min;
            min = tmp;
        }
        return (rand()%(abs(max - min) + 1) + min);
    }
}

#endif

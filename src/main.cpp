#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.h"
#include "GameUtils.h"
#include "RenderWindow.h"
#include "Sprite.h"

int main(int argv, char** args) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) LOG("SDL Init failed: " << SDL_GetError());
    if (!IMG_Init(IMG_INIT_PNG)) LOG("SDL_IMAGE Init failed: " << SDL_GetError());

    srand((unsigned int)time(NULL));

    Game::window.create("SDL2 Game", Game::sWidth, Game::sHeight);
    Game::init();

    bool running = true;
    SDL_Event event;

    const float targetFps = 1 / 5.0f;
    float accumulator = 0;
    float currentTime = utils::getTime();

    while (running) {
        float newTime = utils::getTime();
        Game::dt = newTime - currentTime;
        currentTime = newTime;
        accumulator += Game::dt;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) running = false;

                if (Game::canMove) {
                    switch (event.key.keysym.sym) {
                    case SDLK_w:
                    case SDLK_UP:
                        if (Game::playerDir != DOWN) Game::playerDir = UP;
                        Game::canMove = false;
                        break;
                    case SDLK_s:
                    case SDLK_DOWN:
                        if (Game::playerDir != UP) Game::playerDir = DOWN;
                        Game::canMove = false;
                        break;
                    case SDLK_a:
                    case SDLK_LEFT:
                        if (Game::playerDir != RIGHT) Game::playerDir = LEFT;
                        Game::canMove = false;
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
                        if (Game::playerDir != LEFT) Game::playerDir = RIGHT;
                        Game::canMove = false;
                        break;
                    }
                }
            }
        }

        if (accumulator >= targetFps) {
            Game::update();
            accumulator = 0;
        }
        Game::draw();
    }

    Game::unload();
    SDL_Quit();

    return 0;
}

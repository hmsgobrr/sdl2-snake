#include "Game.h"
#include "GameUtils.h"

RenderWindow Game::window;
float Game::dt;
V2 Game::player;
std::vector<V2> Game::body;
Direction Game::playerDir;
bool Game::canMove;
V2 Game::food;

void Game::init() {
    player = { 2, 7 };
    body.clear();
    body.push_back({ 1, 7 });
    body.push_back({ 0, 7 });
    playerDir = RIGHT;
    canMove = true;
    food = { 13, 7 };
}

void Game::update() {
    for (int i = body.size(); i > 0; i--) body[i] = body[i-1];
    body[0] = player;

	switch (playerDir) {
    case UP:
        player.y--;
        break;
    case DOWN:
        player.y++;
        break;
    case LEFT:
        player.x--;
        break;
    case RIGHT:
        player.x++;
        break;
    }

    canMove = true;

    if (player.x > 16) player.x = 0;
    if (player.x < 0) player.x = 16;
    if (player.y > 14) player.y = 0;
    if (player.y < 0) player.y = 14;

    if (food.x == player.x && food.y == player.y) {
        for (V2& bodyPos : body) {
            while ((food.x == bodyPos.x && food.y == bodyPos.y) ||
                   (food.x == player.x && food.y == player.y)) {
                food = { (float)utils::getRandom(0, 16), (float)utils::getRandom(0, 14) };
            }
        }
        body.push_back({ body[body.size()-1].x, body[body.size()-1].y });
    }

    for (V2& bodyPos : body) {
        if (player.x == bodyPos.x && player.y == bodyPos.y) init();
    }
}

void Game::draw() {
	window.clear();

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 15; j++) {
			if ((i + j) % 2 != 0) {
				window.drawLine(i, j, i, j, { 28, 37, 65, 255 });
			}
		}
	}

    for (V2& bodyPos : body) {
        window.drawLine(bodyPos.x, bodyPos.y, bodyPos.x, bodyPos.y, { 58, 80, 107, 255 });
    }

    window.drawLine(food.x, food.y, food.x, food.y, { 255, 112, 112, 255 });

    window.drawLine(player.x, player.y, player.x, player.y, { 91, 192, 190, 255 });

    window.display();
}

void Game::unload() {
	
}

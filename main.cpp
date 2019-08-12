#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.hpp"

Game* game;

int main(int argc, char *argv[]) {
	game = new Game();
	game->init("test game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return EXIT_SUCCESS;
}
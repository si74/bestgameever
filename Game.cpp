#include "Game.hpp"
#include <stdio.h>

SDL_Texture* playerTexture;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("SDL could not initialize! SDL ERROR: %d", SDL_GetError());
		isRunning = false;
		return;
	}
	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	if (window) {
		printf("window created!\n");
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		printf("renderer created!\n");
	}

	isRunning = true;

	SDL_Surface* tmpSurface = IMG_Load("../assets/player.png");

	playerTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break; 

	}
}

void Game::update() {}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game Cleaned\n");
}
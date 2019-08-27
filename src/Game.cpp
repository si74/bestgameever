#include "Game.hpp"
#include <stdio.h>




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

	SDL_Surface* tmpSurfaceCircle = IMG_Load("../assets/circle.png");
	tex = SDL_CreateTextureFromSurface(renderer, tmpSurfaceCircle);
	SDL_FreeSurface(tmpSurfaceCircle);
    // connects our texture with dest to control position
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

    // adjust height and width of our image box.
    dest.w /= 6;
    dest.h /= 6;

    // sets initial x-position of object
    dest.x = (1000 - dest.w) / 2;

    // sets initial y-position of object
    dest.y = (1000 - dest.h) / 2;

    // controls annimation loop
    close = 0;

    // speed of box
    speed = 300;

}

void Game::handleEvents() {

	SDL_Event event; 

	// Events mangement 
	while (SDL_PollEvent(&event)) { 
		switch (event.type) { 

		case SDL_QUIT:
			// handling of close button 
			isRunning = false; 
			printf("close app\n");
			break; 

		case SDL_KEYDOWN: 
			// keyboard API for key pressed 
			switch (event.key.keysym.scancode) { 
				case SDL_SCANCODE_ESCAPE:
					isRunning = false;
					printf("close app\n");
					break;
				case SDL_SCANCODE_W: 
				case SDL_SCANCODE_UP: 
					dest.y -= speed / 30; 
					break; 
				case SDL_SCANCODE_A: 
				case SDL_SCANCODE_LEFT: 
					dest.x -= speed / 30; 
					break; 
				case SDL_SCANCODE_S: 
				case SDL_SCANCODE_DOWN: 
					dest.y += speed / 30; 
					break; 
				case SDL_SCANCODE_D: 
				case SDL_SCANCODE_RIGHT: 
					dest.x += speed / 30; 
					break; 
				default:
					break;
			} 
		} 
	} 

	// right boundary 
	if (dest.x + dest.w > 1000) {
		x = 1000 - dest.w; 
	}

	// left boundary 
	if (dest.x < 0) {
		dest.x = 0; 
	}

	// bottom boundary 
	if (dest.y + dest.h > 1000) {
		dest.y = 1000 - dest.h; 
	}

	// upper boundary 
	if (dest.y < 0) {
		dest.y = 0; 
	}
}


void Game::update() {
	count++;
	destRect.h = 128;
	destRect.w = 128;


}

void Game::render() {
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, playerTexture, NULL, &destRect);
	SDL_RenderCopy(renderer, tex, NULL, &dest);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game Cleaned\n");
}

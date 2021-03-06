#include "Game.hpp"
#include "TextureManager.hpp"
#include <stdio.h>


SDL_Renderer* Game::renderer = nullptr;

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

	// loads file as texture
	playerTex = TextureManager::LoadTexture("../assets/player.png");
	

	// connects our texture with dest to control position
	SDL_QueryTexture(playerTex, NULL, NULL, &dest.w, &dest.h);

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

	map = new Map();

}

void Game::DrawMap() {
	int type = 0;

	for(int row = 0; row < 20; row++) {
		for(int col = 0;  col < 25; col++) {
			type = map->map[row][col];

			map->dest.x = col * 32;
			map->dest.y = row * 32;

			switch (type) {
				case 0:
					TextureManager::Draw(map->water, map->src, map->dest);
					break;
				case 1: 
					TextureManager::Draw(map->grass, map->src, map->dest);
					break;
				case 2:
					TextureManager::Draw(map->dirt, map->src, map->dest);
					break;
				default:
					break;
			}
		}
	}
}

void Game::renderBlock(SDL_Window* window, SDL_Rect* box) {
	box->w = 10; 
	box->h = 10; 
	box->x = 0;
	box->y = 0; 

	//window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 250, 250, NULL);
	//renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	SDL_RenderClear(renderer);
	//outline rect
	SDL_SetRenderDrawColor(renderer, 0 , 0, 0, 255);
	SDL_RenderDrawRect(renderer, box);
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//fill up rectangle with color
	//SDL_RenderFillRect(renderer, box);
}

void Game::handleEvents() {
	SDL_Event event; 

	// Events mangement 
	while (SDL_PollEvent(&event)) { 

		if (event.type == SDL_KEYDOWN){ 
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
		dest.x = 1000 - dest.w; 
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

	//map->LoadMap(); todo text file with different arrays
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255,255,255,255); // set color to write
	SDL_RenderClear(renderer); // clear renderer with latest set color

	//SDL_Rect block1;
	//renderBlock(window, &block1); // TODO render background function that renders all the blocks, also sets boundaries for player
	map->DrawMap();
	SDL_RenderCopy(renderer, playerTex, NULL, &dest); // player
	//SDL_RenderCopy(renderer, map->water, NULL, &(map->dest));

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Game Cleaned\n");
}

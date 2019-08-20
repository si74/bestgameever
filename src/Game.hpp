#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game {

	public:
		int x = 0;
		int y = 0;
		int close = 0; 

  
		// speed of box 
		int speed = 300; 
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void handleEvents();
		void update();
		void render();
		void clean();

		void playerJump();
		void playerRun();


		bool running() {
			return isRunning;
		};



	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool isRunning;
		int count = 0;
		SDL_Rect dest; 
};

#endif // Game_hpp
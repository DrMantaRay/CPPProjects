#include <SDL.h>
#include "Header.h"
#include <iostream>
#include <memory>



EndlessMazeGame::EndlessMazeGame(): _window_(nullptr),_screenSurface_(nullptr) {
}

int EndlessMazeGame::run() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
	}
	else {
		_window_.reset(SDL_CreateWindow("Endless Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN));
		if (_window_ == nullptr) {
			printf("Window couldn't be created. SDL_Error: %s\n", SDL_GetError());
		}
		else {
			_screenSurface_.reset(SDL_GetWindowSurface(_window_.get()));
			SDL_FillRect(_screenSurface_.get(), nullptr, SDL_MapRGB(_screenSurface_->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(_window_.get());
			SDL_Delay(2000);
		}
		SDL_Quit();
	}
	return 0;
}
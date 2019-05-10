#include <SDL.h>
#include <SDL_image.h>
#include "Header.h"
#include <iostream>
#include <memory>


// default constructor
GameWindow::GameWindow(): _window_(nullptr),_screenRenderer_(nullptr) {
}

// intialize various SDL modules
bool GameWindow::init() {

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
		success = false;
	}
	else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			std::cerr << "Warning: Linear texture filtering not enabled" << std::endl;
		}

		_window_.reset(SDL_CreateWindow("Endless Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN));

		if (_window_ == nullptr) {
			std::cerr << "Window couldn't be created. SDL_Error: %s\n" << SDL_GetError() << std::endl;
			success = false;
		}
		else {
			_screenRenderer_.reset(SDL_CreateRenderer(_window_.get(), -1, SDL_RENDERER_ACCELERATED));
			if (_screenRenderer_ == nullptr) {
				std::cerr << "Renderer could not be created! SDL Error" << SDL_GetError() << std::endl;
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(_screenRenderer_.get(), 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					std::cerr << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << std::endl;
					success = false;
				}
			}
		}
	}
	return success;
}

bool GameWindow::run() {
	if (!init()) {
		std::cerr << "Failed to initialize!" << std::endl;
	}
	else {

	}
	return true;
}

void GameWindow::close() {
	SDL_Quit();
}
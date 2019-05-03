#include <SDL.h>
#include <SDL_image.h>
#include "Header.h"
#include <memory>

bool BasicTexture::loadFromFile(std::string path) {
	bool success = true;
	auto loadedSurface = std::unique_ptr<SDL_Surface, SurfaceDeleter>(IMG_Load(path.c_str));
	if (loadedSurface == nullptr) {
		std::cerr << "Unable to load image: " << path << "SDL_image Error: " << IMG_GetError() << std::endl;
	}
	else {
		_texture_.reset(SDL_CreateTextureFromSurface(EndlessMazeGame::_screenRenderer_.get(), loadedSurface.get()));
	}
}

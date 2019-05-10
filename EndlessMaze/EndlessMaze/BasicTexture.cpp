#include <SDL.h>
#include <SDL_image.h>
#include "Header.h"
#include <memory>

bool BasicTexture::loadFromFile(const std::string &file, SDL_Renderer *renderer) {
	bool success = true;
	auto loadedSurface = std::unique_ptr<SDL_Surface, SurfaceDeleter>(IMG_Load(file.c_str()));
	if (loadedSurface == nullptr) {
		std::cerr << "Unable to load image: " << file << "SDL_image Error: " << IMG_GetError() << std::endl;
	}
	else {
		_texture_.reset(SDL_CreateTextureFromSurface(renderer, loadedSurface.get()));
	}
	return success;
}

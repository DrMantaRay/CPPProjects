#include <SDL.h>
#include <memory>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

struct WindowDeleter;
struct SurfaceDeleter;

struct WindowDeleter {
	void operator()(SDL_Window * sdl_window) const {
		SDL_DestroyWindow(sdl_window);
	}
};

struct SurfaceDeleter {
	void operator()(SDL_Surface * sdl_surface) const {
		SDL_FreeSurface(sdl_surface);
	}
};

class EndlessMazeGame {
	public:
		EndlessMazeGame();
		int run();
	private:
		std::unique_ptr<SDL_Window, WindowDeleter> _window_;
		std::unique_ptr<SDL_Surface, SurfaceDeleter> _screenSurface_;

};


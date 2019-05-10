#include <SDL.h>
#include <memory>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

struct WindowDeleter {
	void operator()(SDL_Window * sdl_window) {
		SDL_DestroyWindow(sdl_window);
	}
};

struct SurfaceDeleter {
	void operator()(SDL_Surface * sdl_surface) {
		SDL_FreeSurface(sdl_surface);
	}
};

struct RendererDeleter {
	void operator()(SDL_Renderer * sdl_renderer) {
		SDL_DestroyRenderer(sdl_renderer);
	}
};

struct TextureDeleter {
	void operator()(SDL_Texture * sdl_texture) {
		SDL_DestroyTexture(sdl_texture);
	}
};

class GameWindow {
	public:
		// Default constructor
		GameWindow();

		// Creates window
		bool init();

		// Renders 
		bool run();
		bool loadMedia();
		void close();
	private:
		// GameWindow data
		std::unique_ptr<SDL_Renderer, RendererDeleter> _screenRenderer_;
		std::unique_ptr<SDL_Window, WindowDeleter> _window_;

};

class BasicTexture {
	public:
		BasicTexture();
		bool loadFromFile(const std::string &path, SDL_Renderer *renderer);
	private:
		std::unique_ptr<SDL_Texture, TextureDeleter> _texture_;
};

#ifndef __GRAPHICS_H
#define __GRAPHICS_H
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif
#include <iostream>
#include <string>

namespace SDLFramework {

	class Graphics
	{
	public:
		static const short SCREEN_WIDTH = 960;
		static const short SCREEN_HEIGHT = 864;
		const char * WINDOW_TITLE = "Tetris";

	private:
		static Graphics * sInstance;
		static bool sInitialized;

		SDL_Window * mWindow;
		SDL_Renderer * mRenderer;

	public:
		static Graphics * Instance();
		static void Release();
		static bool Initialized();

		SDL_Texture * LoadTexture(std::string path);
		SDL_Texture * CreateTextTexture(TTF_Font * font, std::string text, SDL_Color color);
		
		void DrawTexture(SDL_Texture * tex, SDL_Rect * srcRect = nullptr, SDL_Rect * dstRect = nullptr, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void DrawLine(float startX, float startY, float endX, float endY);

		void ClearBackBuffer();
		void Render();

	private:
		Graphics();
		~Graphics();



		bool Init();
	};
}
#endif
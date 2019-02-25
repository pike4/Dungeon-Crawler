#include "Graphics.h"
#include "SDL_Image.h"
#include "World.h"

namespace Graphics
{
    bool init()
    {
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		mWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 900, SDL_WINDOW_SHOWN);
		mScreen = SDL_GetWindowSurface(mWindow);
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		
		return true;
	}

	void update()
	{
		SDL_RenderClear(mRenderer);
		for each(Entity* e in World::updateQueue)
		{
			e->draw();
		}
		SDL_RenderPresent(mRenderer);
	}

#pragma region Utility Functions

	void applyTexture(int x, int y, SDL_Texture* source)
	{
		SDL_Rect src, dest;

		int w, h;
		int tempX = 0;
		int tempY = 0;

		SDL_QueryTexture(source, NULL, NULL, &w, &h);

		//if (xOffset && yOffset)
		//{
		//	tempX = *xOffset;
		//	tempY = *yOffset;
		//}

		dest.x = x;// -tempX + xOffsetInitial;
		dest.y = y;// -tempY + yOffsetInitial;
		dest.w = w;
		dest.h = h;

		src.x = 0;
		src.y = 0;
		src.w = w;
		src.h = h;

		SDL_RenderCopy(mRenderer, source, &src, &dest);
	}

	void applyTexture(int x, int y, int w, int h, double angle, SDL_Texture* source)
	{
		int srcW, srcH;
		SDL_QueryTexture(source, NULL, NULL, &srcW, &srcH);

		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = srcW;
		src.h = srcH;

		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		dst.w = w;
		dst.h = h;

		SDL_RenderCopyEx(mRenderer, source, &src, &dst, angle, NULL, SDL_FLIP_NONE);
	}

#pragma endregion

	SDL_Window* mWindow;
	SDL_Surface* mScreen;
	SDL_Renderer* mRenderer;
}
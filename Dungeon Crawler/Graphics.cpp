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
	SDL_Texture* loadSprite(std::string fileName)
	{
		SDL_Surface* loadedTexture = IMG_Load(fileName.c_str());
		SDL_Texture* optimizedSurface = NULL;

		if (loadedTexture == NULL)
		{
			if (fileName.empty())
			{
				fileName = "NO NAME GIVEN";
			}

			printf("Texture could not be found");
			printf(IMG_GetError());
		}

		else
		{
			optimizedSurface = SDL_CreateTextureFromSurface(mRenderer, loadedTexture);
			SDL_FreeSurface(loadedTexture);
		}

		return optimizedSurface;
	}

	void applyTexture(int x, int y, SDL_Texture* source)
	{
		SDL_Rect dest;
		SDL_Rect src;

		int w;
		int h;
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
#pragma endregion

	SDL_Window* mWindow;
	SDL_Surface* mScreen;
	SDL_Renderer* mRenderer;

	SDL_Texture* deleteThis;
}
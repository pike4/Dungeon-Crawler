#include "InputManager.h"
#include "Game.h"
#include "SDL.h"

namespace InputManager
{
	SDL_Event e;

	void getMouse(int* x, int* y)
	{
		SDL_GetMouseState(x, y);
	}

	void handle(SDL_Event e)
	{
		switch (e.type)
		{
		case SDL_QUIT:
			Game::quit();
			break;

		case SDL_KEYDOWN:
		case SDL_KEYUP:
			break;

		case SDL_MOUSEMOTION:
			break;

		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			break;

		case SDL_MOUSEWHEEL:
			break;

		}
	}

	void update()
	{
		while (SDL_PollEvent(&e))
		{
			handle(e);
		}
	}
}
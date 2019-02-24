#include "InputManager.h"
#include "EventManager.h"
#include "Game.h"
#include "SDL.h"

namespace InputManager
{
	SDL_Event e;

	void getMouse(int* x, int* y)
	{
		SDL_GetMouseState(x, y);
	}

	void handleKeyboard(SDL_Event e)
	{
		int down, opcode;

		if (e.type == SDL_KEYDOWN) {
			down = KEY_DOWN;
		}

		else {
			down = KEY_UP;
		}

		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			opcode = FORWARD_WALK;
			break;
		case SDLK_s:
			opcode = BACK_WALK;
			break;
		case SDLK_d:
			opcode = RIGHT_WALK;
			break;
		case SDLK_a:
			opcode = LEFT_WALK;
			break;
		case SDLK_ESCAPE:
			opcode = PAUSE_PRESS;
			break;
		default:
			opcode = UNKNOWN_EVENT;
		}

		EventManager::handle(Event(opcode, { down }));
	}

	void handleMouseWheel(SDL_Event e)
	{
		if (e.wheel.y > 0)
		{
			EventManager::handle(SPELL_SELECT_UP);
		}

		else
		{
			EventManager::handle(SPELL_SELECT_DOWN);
		}
	}

	void handleMouseButton(SDL_Event e)
	{
		int isDown;
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			isDown = KEY_DOWN;
		}

		else {
			isDown = KEY_UP;
		}

		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			EventManager::handle(Event(PRIMARY_ATTACK, { isDown }));
			EventManager::handle(Event(LEFT_CLICK, { isDown }));
			break;
		case SDL_BUTTON_RIGHT:
			EventManager::handle(Event(SECONDARY_ATTACK, { isDown }));
			EventManager::handle(Event(RIGHT_CLICK, { isDown }));
			break;
		case SDL_BUTTON_MIDDLE:
			EventManager::handle(Event(MIDDLE_CLICK, { isDown }));
			break;
		}
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
			if(e.key.repeat == 0)
				handleKeyboard(e);
			break;

		case SDL_MOUSEMOTION:
			EventManager::handle(MOUSE_MOVED);
			break;

		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEBUTTONDOWN:
			handleMouseButton(e);
			break;

		case SDL_MOUSEWHEEL:
			handleMouseWheel(e);
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
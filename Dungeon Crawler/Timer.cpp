#include "Timer.h"
#include "SDL.h"

void Timer::updateTime()
{
	prev = SDL_GetTicks();
}

void Timer::pause()
{
	blockedAt = SDL_GetTicks();
}

void Timer::resume()
{
	prev += SDL_GetTicks() - blockedAt;
}

// Returns true if the given time has elapsed since update
bool Timer::hasElapsed(Uint32 ms)
{
	return ms < elapsed();
}

// Returns time in milliseconds since the Timer was last updated
Uint32 Timer::elapsed()
{
	return (SDL_GetTicks() - prev);
}

Timer::Timer()
{
	prev = SDL_GetTicks();
	blockedAt = 0;
}
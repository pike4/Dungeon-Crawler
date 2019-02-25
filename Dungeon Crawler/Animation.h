#pragma once
#include "Timer.h"
#include "Element.h"

#include "SDL.h"
#include <vector>

struct Animation : public Element
{
public:
	Animation(int w_, int h_, int speed_);

	void draw(int x, int y);

	std::vector<SDL_Texture*> frames;
	Timer frameTimer;
	int speed;

private:
	int frameIndex = 0;
};
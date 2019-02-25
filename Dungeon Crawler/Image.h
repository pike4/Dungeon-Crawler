#pragma once
#include "Graphics.h"

struct Image
{
	int w, h;
	double angle;
	SDL_Texture* texture;

	void draw(int x, int y);
	void draw(int x, int y, double angle);

	Image(SDL_Texture* texture_, int w_, int h_);
	Image(SDL_Texture* texture_, int w_, int h_, double rotation_);
};
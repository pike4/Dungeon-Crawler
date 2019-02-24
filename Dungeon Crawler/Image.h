#pragma once
#include "Graphics.h"

struct Image
{
	int w, h;
	SDL_Texture* texture;

	void draw(int x, int y);
	void draw(int x, int y, double angle);

	Image(SDL_Texture* texture_ , int w_, int h_);
};
#pragma once
#include "Graphics.h"
#include "Element.h"

class Image : public Element
{
public:
	virtual void draw(int x, int y);
	void draw(int x, int y, double angle);

	Image(SDL_Texture* texture_, int w_, int h_);
	Image(SDL_Texture* texture_, int w_, int h_, double rotation_);

protected:
	SDL_Texture* texture;
};
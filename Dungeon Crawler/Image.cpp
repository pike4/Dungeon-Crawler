#include "Image.h"

Image::Image(SDL_Texture* texture_, int w_, int h_)
	: texture(texture_)
{
	if (w_ == 0 || h_ == 0) {
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	}

	else {
		w = w_;
		h = h_;
	}
}

void Image::draw(int x, int y)
{
	Graphics::applyTexture(x, y, w, h, 0, texture);
}

void Image::draw(int x, int y, double angle)
{
	Graphics::applyTexture(x, y, w, h, angle, texture);
}
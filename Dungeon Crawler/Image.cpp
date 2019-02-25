#include "Image.h"

Image::Image(SDL_Texture* texture_, int w_, int h_, double rotation_)
	: texture(texture_), angle(rotation_)
{
	if (w_ == 0 || h_ == 0) {
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	}

	else {
		w = w_;
		h = h_;
	}
}

Image::Image(SDL_Texture* texture_, int w_, int h_)
	: Image(texture_, w_, h_, 0.0)
{ }

void Image::draw(int x, int y)
{
	Graphics::applyTexture(x, y, w, h, angle, texture);
}

void Image::draw(int x, int y, double angle_)
{
	Graphics::applyTexture(x, y, w, h, angle_, texture);
}
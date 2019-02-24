#pragma once
#include "Image.h"

#include <map>
#include "SDL.h"

namespace Resources
{
	

	void init();

	SDL_Texture* getTexture(int texID);
	Image* getImage(int texID, int w, int h);

	extern std::map<int, SDL_Texture*> textures;
}
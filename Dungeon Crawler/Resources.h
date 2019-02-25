#pragma once
#include "Image.h"
#include "Animation.h"

#include <map>
#include "SDL.h"

namespace Resources
{
	
	// Load resources
	void init();

	// Load animation resources
	void initAnimations();

	// Load texture resources
	void initTextures();

	// Get the texture with the given ID
	SDL_Texture* getTexture(int texID);

	// Get an image from the given texture with the given dimensions
	Image* getImage(int texID, int w, int h);

	// Get the animation with the given ID
	Animation* getAnimation(int animID, int w, int h, int speed);

	// Load a sprite from the given filepath
	SDL_Texture* loadSprite(std::string fileName);

	// Create an animation from the given sprite sheet
	std::vector<SDL_Texture*> loadAnimation(int frX, int frY, int frW, int frH, int sep, std::string file);

	extern std::map<int, std::vector<SDL_Texture*>>	spriteSheets;
	extern std::map<int, SDL_Texture*> textures;
	extern std::map<int, Animation*> animations;
}
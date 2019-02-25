#include "Resources.h"
#include "Graphics.h"
#include "SpriteIds.h"
#include "AnimationIds.h"
#include "Image.h"

#include <array>
#include "SDL.h"
#include "SDL_Image.h"

namespace Resources
{
	void init()
	{
		initTextures();
		initAnimations();
	}

	void initTextures()
	{
		textures[MISSING_TEXTURE] = loadSprite("resources/img/missing_texture.png");
		textures[TEST_MAN_SPRITE] = loadSprite("resources/img/grunt.png");
	}

	void initAnimations()
	{
		spriteSheets[DEFAULT_ANIM] =	loadAnimation(2, 2, 100, 100, 1, "resources/img/default_anim.png");
		spriteSheets[TEST_ANIM] =		loadAnimation(2, 2, 100, 100, 1, "resources/img/test_anim.png");
	}

#pragma region Accessors
	SDL_Texture* getTexture(int texID)
	{
		SDL_Texture* ret = NULL;

		if (textures.find(texID) != textures.end()) {
			ret = textures[texID];
		} else {
			ret = textures[MISSING_TEXTURE];
		}

		return ret;
	}

	Animation* getAnimation(int animID, int w, int h, int speed)
	{
		std::vector<SDL_Texture*> vec;

		if (spriteSheets.find(animID) != spriteSheets.end()) {
			vec = spriteSheets[animID];
		}

		else {
			vec = spriteSheets[DEFAULT_ANIM];
		}

		Animation* ret = new Animation(w, h, speed);
		ret->frames = vec;

		return ret;
	}

	Image* getImage(int texID, int w, int h)
	{
		Image* ret = NULL;

		return new Image(getTexture(texID), w, h);

		/*else if (images.find({ texID, w, h }) != images.end()) {
			ret = images[{texID, w, h}];
		} 
		else {
			ret = new Image(getTexture(texID), w, h);
			images[{texID, w, h}] = ret;
		}
*/
		return ret;
	}
#pragma endregion

#pragma region Loading Functions
	SDL_Texture* loadSprite(std::string fileName)
	{
		SDL_Surface* loadedTexture = IMG_Load(fileName.c_str());
		SDL_Texture* optimizedSurface = NULL;

		if (loadedTexture == NULL)
		{
			if (fileName.empty())
			{
				fileName = "NO NAME GIVEN";
			}

			printf("Texture could not be found");
			printf(IMG_GetError());
		}

		else
		{
			optimizedSurface = SDL_CreateTextureFromSurface(Graphics::mRenderer, loadedTexture);
			SDL_FreeSurface(loadedTexture);
		}

		return optimizedSurface;
	}

	std::vector<SDL_Texture*> loadAnimation(int framesX, int framesY, int frameW, int frameH,
		int seperation, std::string fileName)
	{
		std::vector<SDL_Texture*> ret;

		SDL_Surface* mainSurface = IMG_Load(fileName.c_str());
		SDL_Surface* tempSurface = new SDL_Surface;
		SDL_Rect curFrame = { 0, 0, frameW, frameH };
		SDL_Rect blitFrame = { 0, 0, frameW, frameH };
		int totalFramesIndex = 0;

		for (int i = 0; i < framesX; i++)
		{
			for (int j = 0; j < framesY; j++)
			{
				tempSurface = SDL_CreateRGBSurface(0, frameW, frameH, 32, 0, 0, 0, 0);
				printf(SDL_GetError());
				curFrame.x = j * (frameW + seperation);
				curFrame.y = i * (frameH + seperation);
				SDL_BlitSurface(mainSurface, &curFrame, tempSurface, &blitFrame);
				ret.push_back(SDL_CreateTextureFromSurface(Graphics::mRenderer, tempSurface));
			}
		}
		SDL_FreeSurface(tempSurface);

		return ret;
	}
#pragma endregion
	std::map<int, std::vector<SDL_Texture*>>	spriteSheets;
	std::map<int, SDL_Texture*>				textures;
	std::map<int, Animation*>				animations;
	std::map<std::array<int, 3>, Image*>	images;
}
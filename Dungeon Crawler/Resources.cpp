#include "Resources.h"
#include "Graphics.h"
#include "AutoGen.h"
#include "Image.h"

#include <array>
#include "SDL.h"
#include "SDL_Image.h"

namespace Resources
{
	void init()
	{
		initTextures();
		initSpriteSheets();
		initAnimations();
	}

	void initTextures()
	{
		textures[MISSING_TEXTURE] = loadSprite("resources/img/missing_texture.png");
		textures[TEST_MAN_SPRITE] = loadSprite("resources/img/grunt.png");
	}

	void initSpriteSheets()
	{
		spriteSheets[SHEET_DEFAULT] = loadSpriteSheet("resources/img/default_anim.png");
		spriteSheets[SHEET_TEST] = loadSpriteSheet("resources/img/test_anim.png");

		spriteSheets[SHEET_PLAYER_TEST] = loadSpriteSheet("resources/img/player_test_anim.png");
	}

	void initAnimations()
	{
		frameSets[DEFAULT_ANIM] =	clipAnimation(2, 2, 100, 100, 1, SHEET_DEFAULT);
		frameSets[TEST_ANIM] =		clipAnimation(2, 2, 100, 100, 1, SHEET_TEST);


		int duckAnimW = 78, duckAnimH = 110;
		frameSets[TEST_IDLE] = clipAnimation(1, 3, duckAnimW, duckAnimH, 0, SHEET_PLAYER_TEST, 0 ,0);
		frameSets[TEST_WALK_RIGHT] = clipAnimation(1, 3, duckAnimW, duckAnimH, 0, SHEET_PLAYER_TEST, 0, duckAnimH * 1);
		frameSets[TEST_WALK_LEFT] = clipAnimation(1, 3, duckAnimW, duckAnimH, 0, SHEET_PLAYER_TEST, 0, duckAnimH * 2);
		frameSets[TEST_WALK_FORWARD] = clipAnimation(1, 3, duckAnimW, duckAnimH, 0, SHEET_PLAYER_TEST, 0, duckAnimH * 3);
		frameSets[TEST_WALK_BACK] = clipAnimation(1, 3, duckAnimW, duckAnimH, 0, SHEET_PLAYER_TEST, 0, 0);
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

	SDL_Surface* getSpriteSheet(int texID)
	{
		SDL_Surface* ret = NULL;

		if (spriteSheets.find(texID) != spriteSheets.end()) {
			ret = spriteSheets[texID];
		}
		else {
			ret = spriteSheets[SHEET_DEFAULT];
		}

		return ret;
	}

	Animation* getAnimation(int animID, int w, int h, int speed)
	{
		std::vector<SDL_Texture*> vec;

		if (frameSets.find(animID) != frameSets.end()) {
			vec = frameSets[animID];
		}

		else {
			vec = frameSets[DEFAULT_ANIM];
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

	SDL_Surface* loadSpriteSheet(std::string fileName)
	{
		return IMG_Load(fileName.c_str());
	}

	std::vector<SDL_Texture*> clipAnimation(int framesX, int framesY, int frameW, int frameH, int seperation, int sheetID, int startX, int startY)
	{
		std::vector<SDL_Texture*> ret;

		SDL_Surface* mainSurface = getSpriteSheet(sheetID);
		SDL_Surface* tempSurface = new SDL_Surface;
		SDL_Rect curFrame = { startX, startY, frameW, frameH };
		SDL_Rect blitFrame = { 0, 0, frameW, frameH };
		int totalFramesIndex = 0;

		for (int i = 0; i < framesX; i++)
		{
			for (int j = 0; j < framesY; j++)
			{
				tempSurface = SDL_CreateRGBSurface(0, frameW, frameH, 32, 0, 0, 0, 0);
				printf(SDL_GetError());
				curFrame.x = startX + j * (frameW + seperation);
				curFrame.y = startY + i * (frameH + seperation);
				SDL_BlitSurface(mainSurface, &curFrame, tempSurface, &blitFrame);
				ret.push_back(SDL_CreateTextureFromSurface(Graphics::mRenderer, tempSurface));
			}
		}
		SDL_FreeSurface(tempSurface);

		return ret;
	}
#pragma endregion

	std::map<int, SDL_Surface*>				spriteSheets;
	std::map<int, std::vector<SDL_Texture*>>	frameSets;
	std::map<int, SDL_Texture*>				textures;
	std::map<int, Animation*>				animations;
	std::map<std::array<int, 3>, Image*>	images;
}
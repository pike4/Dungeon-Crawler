#include "Resources.h"
#include "Graphics.h"
#include "SpriteIds.h"
#include "Image.h"

#include <array>

namespace Resources
{
	std::map<int, SDL_Texture*>				textures;
	std::map<std::array<int, 3>, Image*>	images;

	void init()
	{
		textures[MISSING_TEXTURE] = Graphics::loadSprite("resources/img/missing_texture.png");
		textures[TEST_MAN_SPRITE] = Graphics::loadSprite("resources/img/grunt.png");
	}

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

	Image* getImage(int texID, int w, int h)
	{
		Image* ret = NULL;

		if (textures.find(texID) == textures.end()) {
			ret = getImage(MISSING_TEXTURE, w, h);
			printf("Error, undefined texture\n");
		} 
		else if (images.find({ texID, w, h }) != images.end()) {
			ret = images[{texID, w, h}];
		} 
		else {
			ret = new Image(getTexture(texID), w, h);
			images[{texID, w, h}] = ret;
		}

		return ret;
	}
}
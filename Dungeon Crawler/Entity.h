#pragma once
#include "InputManager.h"
#include "Drawable.h"
#include "Graphics.h"
#include "Resources.h"
#include "SpriteIds.h"
#include "Image.h"

class Entity : public Drawable
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;

	Entity(int x_, int y_) : x(x_), y(y_)
	{ }

	int x, y;
};

class MouseFollowTest : public Entity
{
public:

	int goalX, goalY;
	Image* image;

	MouseFollowTest(int x_, int y_) : Entity(x_, y_)
	{
		image = Resources::getImage(TEST_MAN_SPRITE, 30, 200);
	}

	virtual void draw()
	{
		image->draw(x, y);
	}

	virtual void update()
	{
		InputManager::getMouse(&goalX, &goalY);

		if (goalX > x) x += 1;
		else x -= 1;
		if (goalY > y) y += 1;
		else y -= 1;
	}
};

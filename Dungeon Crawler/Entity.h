#pragma once
#include "InputManager.h"
#include "Drawable.h"
#include "Graphics.h"

class Entity : public Drawable
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;

	Entity(int x_, int y_) : x(x_), y(y_)
	{ }

	int x, y;
};

class Image : public Entity
{
public:

	int goalX, goalY;
	Image(int x_, int y_) : Entity(x_, y_)
	{}

	virtual void draw()
	{
		Graphics::applyTexture(x, y, Graphics::deleteThis);
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

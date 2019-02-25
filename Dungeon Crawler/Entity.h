#pragma once
#include "InputManager.h"
#include "Drawable.h"
#include "Graphics.h"
#include "Resources.h"
#include "SpriteIds.h"
#include "Image.h"
#include "AnimationIds.h"

// Entity life cycles
#define OBJ_PERMANENT	0
#define OBJ_ROOM_BOUND	1
#define OBJ_TEMP		2

class Entity : public Drawable
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;

	Entity(int x_, int y_) : x(x_), y(y_)
	{ 
		lifeCycle = OBJ_ROOM_BOUND;
	}

	int x, y;
	int lifeCycle;
};

class MouseFollowTest : public Entity
{
public:
	int goalX, goalY;
	Image* image;

	MouseFollowTest(int x_, int y_) : Entity(x_, y_)
	{
		image = Resources::getImage(TEST_MAN_SPRITE, 20, 20);
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

		image->angle += 1;
	}
};

class AnimTest : public Entity
{
public:
	int shrinkRate = 1;

	Animation* anim;
	AnimTest(int x_, int y_) : Entity(x_, y_) {
		anim = Resources::getAnimation(TEST_ANIM, 100, 100, 700);
	}
	virtual void update() { 
		anim->w += shrinkRate; 
		anim->h +=shrinkRate;
		if (anim->h > 200 && shrinkRate > 0) {
			shrinkRate = -1;
		}
		else if (shrinkRate < 0 && anim->h < 100)
		{
			shrinkRate = 1;
		}
	}
	virtual void draw() {
		anim->draw(x, y);
	}
};

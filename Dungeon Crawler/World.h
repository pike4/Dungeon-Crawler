#pragma once
#include "Entity.h"

#include <vector>

namespace World
{
	void add(Entity* newObject);

	void update();

	extern std::vector<Entity*> updateQueue;
}
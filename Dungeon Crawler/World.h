#pragma once
#include "Entity.h"

#include <vector>

namespace World
{
	// Add a new entity to the world
	void add(Entity* newObject);

	// Delete all objects in the world
	void clear();

	// Handle an update step
	void update();

	// The vector of all Entities in the world
	extern std::vector<Entity*> updateQueue;
}
#pragma once
#include "Entity.h"

#include <vector>
// Tilemap, walls, entities to be spawned on entry, and doors
// This is not a CORE Room
class Room
{
	// Vector of entities to be spawned when the room is entered. 
	// Also used to store objects for when room is re-entered
	std::vector<Entity*> population;
};
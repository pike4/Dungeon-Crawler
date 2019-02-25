#pragma once
#include "Room.h"

#include <map>

class Environment
{
	Room* getRoom(int id);


	// Maps rooms in environment to their IDs
	std::map<int, Room*> rooms;
};
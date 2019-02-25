#include "Environment.h"

Room* Environment::getRoom(int id)
{
	Room* ret = NULL;

	if (rooms.find(id) != rooms.end())
	{
		ret = rooms[id];
	}

	else
	{
		// TODO: figure out a default room to return
		printf("Error, undefined room id: %d\n", id);
	}

	return ret;
}
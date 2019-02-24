#include "World.h"

namespace World
{
	void add(Entity* newObject)
	{
		updateQueue.push_back(newObject);
	}

	void update()
	{
		for each(Entity* e in updateQueue)
		{
			e->update();
		}
	}

	std::vector<Entity*> updateQueue;
}
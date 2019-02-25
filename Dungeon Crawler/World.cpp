#include "World.h"

namespace World
{
	void add(Entity* newObject)
	{
		updateQueue.push_back(newObject);
	}

	void clear()
	{
		//TODO: object pooling system so that these are recycled and returned to the pool
		for each(Entity* e in updateQueue)
		{
			delete e;
		}

		updateQueue.clear();
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
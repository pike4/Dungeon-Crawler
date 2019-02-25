#include "EventManager.h"
#include "Graphics.h"
#include "InputManager.h"
#include "World.h"
#include "sdl.h"
#include "Entity.h"

#undef main

int main()
{
	Graphics::init();
	Resources::init();

	World::add(new MouseFollowTest(100, 100));
	World::add(new MouseFollowTest(200, 200));
	World::add(new MouseFollowTest(300, 300));
	World::add(new MouseFollowTest(400, 400));

	World::clear();

	EVPrinter keyP = EVPrinter();

	for (int i = 0; i < NUM_EVENTS; i++)
	{
		EventManager::add(&keyP, i);
	}

	while (true)
	{
		InputManager::update();
		World::update();
		Graphics::update();
		SDL_Delay(20);
	}
}

void testQueues()
{
    Printer* p1 = new Printer;
    Printer* p2 = new Printer;
    Printer* p3 = new Printer;


    EventManager::add(p1, 1);
    EventManager::add(p2, 1);
    EventManager::add(p3, 1);

    EventManager::add(p1, 2);
    EventManager::add(p2, 2);

    EventManager::add(p1, 3);
    EventManager::add(p2, 3);
    EventManager::add(p3, 3);

    EventManager::handle(1);
    EventManager::handle(2);
    EventManager::handle(3);

    EventManager::remove(p1, 1);
    EventManager::handle(1);


    EventManager::remove(p1, 2);
    EventManager::handle(2);
}
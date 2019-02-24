#pragma once
#include "World.h"
#include "Graphics.h"
#include "InputManager.h"

namespace Game
{
	// Initialize subsystems
	void start();

	// Run the game
	void run();

	// Shut the game down
	void quit();
}
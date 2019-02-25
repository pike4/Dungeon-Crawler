#pragma once
#include "States.h"
#include "Drawable.h"
#include "Animation.h"

#include "SDL.h"
#include <vector>

// Provides an update function to the main loop and utility functions to the rest of the engine for interacting with SDL
namespace Graphics
{
    // Draw in the appropriate order based on game state
    void update();

    // Initialize Drawing functions
    bool init();

	// Draw the given file at the given screen coordinates
	void applyTexture(int x, int y, SDL_Texture* source);
	void applyTexture(int x, int y, int w, int h, double angle, SDL_Texture* source);

	extern SDL_Window* mWindow;
	extern SDL_Surface* mScreen;
	extern SDL_Renderer* mRenderer;
};
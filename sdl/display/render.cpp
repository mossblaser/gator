#include <SDL.h>
#include <SDL_image.h>
#include "sdl/event_handler.h"
#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnRender(void)
{
	// TODO: Draw stuff!
	
	SDL_Flip(display);
} // Display::OnRender



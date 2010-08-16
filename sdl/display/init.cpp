#include <SDL.h>
#include <SDL_image.h>
#include "sdl/event_handler.h"
#include "sdl/display.h"

using namespace gator::sdl;

bool
Display::OnInit(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	display = SDL_SetVideoMode(VWIDTH, VHEIGHT, VDEPTH,
	                           SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (display == NULL) return false;
	
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if ((IMG_Init(flags) & flags) != flags) return false;
	
	return true;
} // Display::OnInit

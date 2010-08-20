#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnLoop(void)
{
	static int ticks = 0;
	static int frame = 0;
	
	if (((frame ++) % 100) == 0) {
		char caption[20];
		snprintf(caption, 19,
		         "Gator (%d fps)", (100 * 1000) / (SDL_GetTicks() - ticks));
		SDL_WM_SetCaption(caption, NULL);
		
		ticks = SDL_GetTicks();
	}
} // Display::OnLoop


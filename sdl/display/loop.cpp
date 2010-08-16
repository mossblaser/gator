#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnLoop(void)
{
	static int ticks = 0;
	static int frame = 0;
	
	if (((frame ++) % 100) == 0) {
		printf("%d fps\n", (100 * 1000) / (SDL_GetTicks() - ticks));
		ticks = SDL_GetTicks();
	}
} // Display::OnLoop


#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnLoop(void)
{
	// Display FPS in window title
	static int ticks = 0;
	static int frame = 0;
	
	if (((frame ++) % 100) == 0) {
		char caption[20];
		snprintf(caption, 19,
		         "Gator (%d fps)", (100 * 1000) / (SDL_GetTicks() - ticks));
		SDL_WM_SetCaption(caption, NULL);
		
		ticks = SDL_GetTicks();
	}
	
	
	// Resize after a delay
	if (last_resize_ticks != 0
	    && resize_width != -1
	    && resize_height != -1
	    && SDL_GetTicks() - last_resize_ticks > DISPLAY_RESIZE_DELAY_TICKS) {
		DoResize(resize_width, resize_height);
		last_resize_ticks = 0;
		resize_width = -1;
		resize_height = -1;
	}
} // Display::OnLoop


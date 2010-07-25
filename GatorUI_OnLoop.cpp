#include "GatorUI.h"

void
GatorUI::OnLoop(void)
{
	static int ticks = 0;
	static int frame = 0;
	
	if (((frame ++) % 100) == 0) {
		printf("%d fps\n", (100 * 1000) / (SDL_GetTicks() - ticks));
		
		ticks = SDL_GetTicks();
	}
	
	if (!canvas->Draw(display, canvas_x, canvas_y))
		printf("canvas->Draw failed!\n");
}


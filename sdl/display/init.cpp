#include "sdl/display.h"
#include "ui/canvas.h"

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
	
	// Push the canvas onto the widgets vector
	widgets.push_back(new gator::ui::Canvas(NULL, display));
	
	return true;
} // Display::OnInit

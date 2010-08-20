#include "sdl/display.h"
#include "ui/canvas.h"

using namespace gator::sdl;

bool
Display::OnInit(void)
{
	width = VWIDTH;
	height = VHEIGHT;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	display = SetVideoMode();
	if (display == NULL) return false;
	
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if ((IMG_Init(flags) & flags) != flags) return false;
	
	// Push the canvas onto the widgets vector
	gator::ui::Canvas *canvas = new gator::ui::Canvas(NULL, display);
	canvas->SetSize(VWIDTH, VHEIGHT);
	widgets.push_back(canvas);
	
	return true;
} // Display::OnInit


SDL_Surface *
Display::SetVideoMode(void)
{
	return SDL_SetVideoMode(GetWidth(), GetHeight(), VDEPTH,
	                        SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
}

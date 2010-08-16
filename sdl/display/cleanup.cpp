#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnCleanup(void)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		delete (*widget);
	}
	
	SDL_FreeSurface(display);
	IMG_Quit();
	SDL_Quit();
} // Display::OnCleanup


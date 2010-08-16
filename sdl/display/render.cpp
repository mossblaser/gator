#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnRender(void)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		(*widget)->Draw();
	}
	
	SDL_Flip(display);
} // Display::OnRender



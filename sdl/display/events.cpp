#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnQuit(void)
{
	running = false;
} // Display::OnCleanup



void
Display::OnMouseMove(int x, int y, int relx, int rely,
                     bool left, bool right, bool middle)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		if ((*widget)->OnMouseMove(x, y, relx, rely, left, right, middle))
			return;
	}
} // Display::OnMouseMove

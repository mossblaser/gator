#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnQuit(void)
{
	running = false;
} // Display::OnCleanup



void
Display::OnButtonDown(int x, int y,
                      bool left, bool right, bool middle)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		if ((*widget)->OnButtonDown(x - (*widget)->GetX(), y - (*widget)->GetY(),
		                            left, right, middle))
			return;
	}
} // Display::OnButtonDown


void
Display::OnButtonUp(int x, int y,
                      bool left, bool right, bool middle)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		if ((*widget)->OnButtonUp(x - (*widget)->GetX(), y - (*widget)->GetY(),
		                          left, right, middle))
			return;
	}
} // Display::OnButtonUp


void
Display::OnMouseMove(int x, int y, int relx, int rely,
                     bool left, bool right, bool middle)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		if ((*widget)->OnMouseMove(x - (*widget)->GetX(), y - (*widget)->GetY(),
		                           relx, rely, left, right, middle))
			return;
	}
} // Display::OnMouseMove


void
Display::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		if ((*widget)->OnKeyUp(sym, mod, unicode))
			return;
	}
} // Display::OnMouseMove

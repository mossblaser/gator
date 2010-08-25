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
		if ((*widget)->OnButtonDown(x, y, left, right, middle))
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
		if ((*widget)->OnButtonUp(x, y, left, right, middle))
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
		if ((*widget)->OnMouseMove(x, y, relx, rely, left, right, middle))
			return;
	}
} // Display::OnMouseMove


void
Display::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	// Ignore numlock/capslock
	mod = (SDLMod) (mod & ~(KMOD_NUM | KMOD_CAPS));
	
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		if ((*widget)->OnKeyUp(sym, mod, unicode))
			return;
	}
} // Display::OnMouseMove


void
Display::OnResize(int new_width, int new_height)
{
	// XXX: This event needs to be stalled somehow to allow WMs with live-resize
	// to work properly without serious buggage.
	
	width = new_width;
	height = new_height;
	display = SetVideoMode();
	
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		(*widget)->SetSize(new_width-200, new_height-200);
		(*widget)->SetSurf(display);
	}
} // Display::OnResize

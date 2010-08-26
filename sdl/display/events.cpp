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
	if (last_resize_ticks == 0) {
		DoResize(new_width, new_height);
		resize_width = -1;
		resize_height = -1;
	} else {
		resize_width = new_width;
		resize_height = new_height;
	}
	
	last_resize_ticks = SDL_GetTicks();
} // Display::OnResize


void
Display::DoResize(int new_width, int new_height)
{
	width = new_width;
	height = new_height;
	display = SetVideoMode();
	
	std::vector<gator::ui::Widget*>::iterator widget;
	for (widget = widgets.begin();
	     widget != widgets.end();
	     ++widget) {
		(*widget)->SetSurf(display);
		(*widget)->SetSize(new_width, new_height);
	}
} // Display::DoResize

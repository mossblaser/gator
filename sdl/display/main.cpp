#include "sdl/display.h"

int
main(int argc, char *argv[])
{
	gator::sdl::Display display;
	return display.Main();
} // main



using namespace gator::sdl;


Display::Display(void) : EventHandler()
{
	display = NULL;
	running = true;
	last_resize_ticks = 0;
	resize_width = -1;
	resize_height = -1;
} // Display::Display

Display::~Display(void)
{
	// Do nothing...
}


int
Display::Main(void)
{
	if (!OnInit()) {
		return -1;
	}
	
	// Main-loop
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			OnEvent(&event);
		}
		
		OnLoop();
		OnRender();
	}
	
	OnCleanup();
	
	return 0;
} // Display::Main


int Display::GetWidth(void) {return width;}
int Display::GetHeight(void) {return height;}

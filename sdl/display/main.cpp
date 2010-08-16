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


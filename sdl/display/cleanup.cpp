#include <SDL.h>
#include <SDL_image.h>
#include "sdl/event_handler.h"
#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnCleanup(void)
{
	SDL_FreeSurface(display);
	IMG_Quit();
	SDL_Quit();
} // Display::OnCleanup


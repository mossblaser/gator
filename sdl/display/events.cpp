#include <SDL.h>
#include <SDL_image.h>
#include "sdl/event_handler.h"
#include "sdl/display.h"

using namespace gator::sdl;

void
Display::OnQuit(void)
{
	running = false;
} // Display::OnCleanup


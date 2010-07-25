#include "GatorUI.h"

void
GatorUI::OnEvent(SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		running = false;
}

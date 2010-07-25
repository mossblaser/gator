#include "GatorUI.h"

void
GatorUI::OnCleanup(void)
{
	delete element;
	delete element2;
	delete canvas;
	delete pallet;
	
	SDL_FreeSurface(display);
	IMG_Quit();
	SDL_Quit();
}



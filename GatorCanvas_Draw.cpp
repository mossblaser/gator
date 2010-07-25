#include "GatorCanvas.h"


bool
GatorCanvas::Draw(SDL_Surface *target_surf, int x, int y)
{
	// Sanity checks
	if (surf   == NULL) return false;
	if (pallet == NULL) return false;
	
	DrawGrid();
	
	std::list<GatorElement *>::iterator i;
	for (i = elements.begin(); i != elements.end(); ++i)
		(*i)->Draw(surf);
	
	SDL_Rect dest_rect;
	dest_rect.x = x;
	dest_rect.y = y;
	
	SDL_BlitSurface(surf, NULL, target_surf, &dest_rect);
	
	return true;
}

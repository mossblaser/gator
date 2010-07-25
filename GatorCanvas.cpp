#include "GatorCanvas.h"

GatorCanvas::GatorCanvas(void)
{
	w = 1;
	h = 1;
	
	scale = 1;
	
	viewport_xp = 0;
	viewport_yp = 0;
	
	pallet = NULL;
	surf = NULL;
	
	pan_mode = false;
}

GatorCanvas::~GatorCanvas(void)
{
	if (surf != NULL)
		SDL_FreeSurface(surf);
}


int
GatorCanvas::GetMaxX(void)
{
	return GRID_SIZE;
}


int
GatorCanvas::GetMaxY(void)
{
	return GRID_SIZE;
}


bool
GatorCanvas::SetScale(int new_scale)
{
	scale = new_scale;
	return true;
}

bool
GatorCanvas::SetSize(int new_w, int new_h)
{
	w = new_w;
	h = new_h;
	
	if (surf != NULL)
		SDL_FreeSurface(surf);
	
	SDL_Surface *tmp_surf;
	tmp_surf = SDL_CreateRGBSurface(SDL_HWSURFACE,
	                                new_w, new_h, VDEPTH, 0,0,0,0);
	
	surf = SDL_DisplayFormat(tmp_surf);
	SDL_FreeSurface(tmp_surf);
	
	return surf != NULL;
}


int
GatorCanvas::GetW(void)
{
	return w;
}


int
GatorCanvas::GetH(void)
{
	return h;
}


void
GatorCanvas::SetPallet(GatorPallet *new_pallet)
{
	pallet = new_pallet;
}


GatorPallet *
GatorCanvas::GetPallet(void)
{
	return pallet;
}

void
GatorCanvas::AddElement(GatorElement *new_element)
{
	elements.push_back(new_element);
}

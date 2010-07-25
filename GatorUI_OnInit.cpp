#include "GatorUI.h"

bool
GatorUI::OnInit(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	display = SDL_SetVideoMode(VWIDTH, VHEIGHT, VDEPTH,
	                           SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (display == NULL)
		return false;
	
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if ((IMG_Init(flags) & flags) != flags)
		return false;
	
	canvas = new GatorCanvas();
	if (canvas == NULL)
		return false;
	
	pallet = new GatorPallet();
	if (pallet == NULL)
		return false;
	
	pallet->background       = 0x333333FF;
	pallet->grid_minor       = 0x444444FF;
	pallet->grid_major       = 0x555555FF;
	pallet->element_normal   = 0xCCCCCCFF;
	pallet->element_selected = 0xFFAA00FF;
	
	canvas->SetPallet(pallet);
	canvas->SetScale(10);
	canvas->SetSize(VWIDTH-20, VHEIGHT-20);
	
	/* TEST CODE */
		element = new GatorElement(canvas);
		element->SetX(20);
		element->SetY(10);
		element->Selected(false);
		
		element2 = new GatorElement(canvas);
		element2->SetX(20);
		element2->SetY(20);
		element2->Selected(true);
		
		canvas->AddElement(element);
		canvas->AddElement(element2);
	/* END TEST CODE */
	
	return true;
}

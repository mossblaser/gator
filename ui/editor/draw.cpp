#include "ui/editor.h"

using namespace gator::ui;


bool
Editor::Draw(void)
{
	SDL_Surface *surf   = GetSurf();
	Pallet      *pallet = GetPallet();
	if (surf == NULL || pallet == NULL)
		return false;
	
	int l = GetX();
	int r = l + GetWidth() - 1;
	int t = GetY();
	int b = t + GetHeight() - 1;
	
	// Canvas
	Canvas *canvas = GetCanvas();
	if (canvas)
		canvas->Draw();
	
	// Toolbox
	int tb_t = b - EDITOR_TOOLBOX_HEIGHT;
	boxColor(surf, l ,tb_t, r, b, pallet->GetToolboxBG());
	hlineColor(surf, l ,r, tb_t, pallet->GetToolboxBorder());
	
	return true;
} // Editor::Draw

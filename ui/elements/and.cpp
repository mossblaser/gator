#include "ui/elements/and.h"

using namespace gator::ui;

ANDGate::ANDGate(int x, int y) :
Selectable(x, y, AND_GATE_WIDTH, AND_GATE_HEIGHT)
{
	// Do nothing...
} // ANDGate::ANDGate


ANDGate::~ANDGate(void)
{
	// Do nothing...
} // ANDGate::~ANDGate


bool
ANDGate::Draw(Canvas *canvas)
{
	if (canvas == NULL)
		return false;
	
	SDL_Surface *surf   = canvas->GetSurf();
	Pallet      *pallet = canvas->GetPallet();
	if (surf == NULL || pallet == NULL)
		return false;
	
	int l = canvas->XS(GetX());
	int r = canvas->XS(GetX() + GetWidth());
	int t = canvas->YS(GetY());
	int b = canvas->YS(GetY() + GetHeight());
	
	// Inner sizes (for the gate)
	int il  = canvas->XS(GetX() + 1);
	int ir  = canvas->XS(GetX() + (GetWidth()/2));
	
	// The tip of the gate
	int ir2 = canvas->XS(GetX() + GetWidth() - 1);
	int c   = canvas->YS(GetY() + (GetHeight()/2));
	
	// Input Wires
	int iwt = canvas->YS(GetY() + 1);
	int iwb = canvas->YS(GetY() + GetHeight() - 1);
	
	Uint32 colour = IsSelected() ? pallet->GetElementSel()
	                             : pallet->GetElement();
	
	// XXX: Approximation!
	// Gate
	Sint16 vx[] = {il, il, ir, ir2, ir, il};
	Sint16 vy[] = {b,  t,  t,  c,   b,  b};
	polygonColor(surf, vx, vy, 6, colour);
	
	// Wires
	lineColor(surf, l, iwt, il, iwt, colour); // Left Top
	lineColor(surf, l, iwb, il, iwb, colour); // Left Bottom
	lineColor(surf, ir2, c, r, c, colour); // Right
	
	return true;
} // ANDGate::Draw


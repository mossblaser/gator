#include "ui/elements/xor.h"

using namespace gator::ui;

XORGate::XORGate(int x, int y) :
Selectable(x, y, AND_GATE_WIDTH, AND_GATE_HEIGHT)
{
	// Do nothing...
} // XORGate::XORGate


XORGate::~XORGate(void)
{
	// Do nothing...
} // XORGate::~XORGate


bool
XORGate::Draw(Canvas *canvas)
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
	int il2  = canvas->XS(GetX() + 2);
	int ir  = canvas->XS(GetX() + (GetWidth()/2));
	
	// XXX: Nasty hack
	int il3  = canvas->XS(GetX() + 1) + (canvas->GetScale()/2);
	
	// Inner-inner back of gate
	int iil  = il2;
	int iil2  = canvas->XS(GetX() + 3);
	
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
	Sint16 vx[] = {iil, iil2, iil, ir, ir2, ir, iil};
	Sint16 vy[] = {b,   c,    t,   t,  c,   b,  b};
	polygonColor(surf, vx, vy, 7, colour);
	
	lineColor(surf, il, t, il2, c, colour);
	lineColor(surf, il, b, il2, c, colour);
	
	// Wires
	lineColor(surf, l, iwt, il3, iwt, colour); // Left Top
	lineColor(surf, l, iwb, il3, iwb, colour); // Left Bottom
	lineColor(surf, ir2, c, r, c, colour); // Right
	
	return true;
} // XORGate::Draw


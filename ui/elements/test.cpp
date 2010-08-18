#include "ui/elements/test.h"

using namespace gator::ui;

TestElement::TestElement(int x, int y) :
Element(x, y, 10, 5),
Selectable()
{
	// Do nothing...
} // TestElement::TestElement


TestElement::~TestElement(void)
{
	// Do nothing...
} // TestElement::~TestElement


bool
TestElement::Draw(Canvas *canvas)
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
	
	Uint32 colour = IsSelected() ? pallet->GetElementSel()
	                             : pallet->GetElement();
	
	rectangleColor(surf, l, t, r, b, colour);
	lineColor(surf, l, t, r, b, colour);
	lineColor(surf, r, t, l, b, colour);
	
	return true;
} // TestElement::Draw

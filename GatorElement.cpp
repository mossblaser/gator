#include "GatorElement.h"

GatorElement::GatorElement(GatorCanvas *new_canvas)
{
	canvas = new_canvas;
	
	x = 0;
	y = 0;
	w = 10;
	h = 5;
	
	selected = false;
}


void
GatorElement::SetX(int new_x)
{
	x = new_x;
}


int
GatorElement::GetX(void)
{
	return x;
}


void
GatorElement::SetY(int new_y)
{
	y = new_y;
}


int
GatorElement::GetY(void)
{
	return y;
}


void
GatorElement::Selected(bool new_selected)
{
	selected = new_selected;
}


bool
GatorElement::Selected(void)
{
	return selected;
}


bool
GatorElement::Draw(SDL_Surface *surf)
{
	int xp  = canvas->XToXP(x),
	    yp  = canvas->YToYP(y),
	    x2p = canvas->XToXP(x+w),
	    y2p = canvas->XToXP(y+h);
	
	Uint32 color = Selected() ? canvas->GetPallet()->element_selected
	                          : canvas->GetPallet()->element_normal;
	
	rectangleColor(surf, xp, yp, x2p, y2p, color);
	lineColor(surf, xp, yp, x2p, y2p, color);
	lineColor(surf, xp, y2p, x2p, yp, color);
	
	return true;
}

bool
GatorElement::AtPosition(int targ_x, int targ_y)
{
	return (targ_x >= x && targ_x <= (x + w)
	        && targ_y >= y && targ_y <= (y + h));
}

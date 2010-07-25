#include "GatorCanvas.h"

void
GatorCanvas::OnButtonDown(int xp, int yp, bool left, bool right, bool middle)
{
	int x = XPToX(xp),
	    y = YPToY(yp);
	printf("click: (%d, %d)\n", x, y);
	
	if (left) {
		OnSelect(x, y, SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT));
	}
}


void
GatorCanvas::OnSelect(int x, int y, bool accumulate)
{
	std::list<GatorElement *>::iterator i;
	GatorElement *element;
	for (i = elements.begin(); i != elements.end(); ++i) {
		element = (*i);
		
		bool select;
		if (accumulate && element->Selected()) {
			select = !element->AtPosition(x,y);
		} else {
			select = element->AtPosition(x, y)
		            || (accumulate && element->Selected());
		}
		element->Selected(select);
	}
}

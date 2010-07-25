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
GatorCanvas::OnButtonUp(int xp, int yp, bool left, bool right, bool middle)
{
	int x = XPToX(xp),
	    y = YPToY(yp);
}


void
GatorCanvas::OnMouseMove(int xp, int yp, int relxp, int relyp,
                         bool left, bool right, bool middle)
{
	if (pan_mode || middle)
		OnPan(relxp, relyp);
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


void
GatorCanvas::OnPan(int relxp, int relyp)
{
	viewport_xp -= relxp;
	viewport_yp -= relyp;
	
	viewport_xp = viewport_xp > 0 ? viewport_xp : 0;
	viewport_yp = viewport_yp > 0 ? viewport_yp : 0;
	
	/* XXX: This acts with a juddering effect... */
	viewport_xp = viewport_xp < XToXP(GRID_SIZE) - GetW()
	              ? viewport_xp : XToXP(GRID_SIZE) - GetW() - 1;
	viewport_yp = viewport_yp < YToYP(GRID_SIZE) - GetH()
	              ? viewport_yp : YToYP(GRID_SIZE) - GetH() - 1;
}

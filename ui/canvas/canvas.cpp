#include "ui/canvas.h"

using namespace gator::ui;


Canvas::Canvas(Widget *parent, SDL_Surface *surf) :
BlitWidget(parent, surf)
{
	SetScale(7);
	SetOffsetX(0);
	SetOffsetY(0);
	
	grid = new Grid();
	pallet = new Pallet();
} // Canvas::Canvas


Canvas::~Canvas(void)
{
	delete pallet;
} // Canvas::~Canvas



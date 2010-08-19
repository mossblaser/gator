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
	
	
	// XXX: Testing...
	
	int x, y;
	for (x = 0; x < 100; x++)
		for (y = 0; y < 100; y++)
			elements.push_back(new TestElement(x*10,y*5));
	
	// XXX: End Testing...
} // Canvas::Canvas


Canvas::~Canvas(void)
{
	// XXX Testing-related (possibly just for now)
	std::vector<Element*>::iterator element;
	for (element = elements.begin();
	     element != elements.end();
	     ++element) {
		delete (*element);
	}
	
	delete pallet;
} // Canvas::~Canvas



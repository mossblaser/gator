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
	
	drag_started = false;
	
	
	// XXX: Testing...
	
	int x, y;
	for (x = 0; x < 10; x++) {
		for (y = 0; y < 10; y++) {
			TestElement *element = new TestElement(x*15, y*10);
			elements.push_back(element);
		}
	}
	
	// XXX: End Testing...
} // Canvas::Canvas


Canvas::~Canvas(void)
{
	// XXX Testing-related (possibly just for now)
	std::vector<Selectable*>::iterator element;
	for (element = elements.begin();
	     element != elements.end();
	     ++element) {
		delete (*element);
	}
	
	delete pallet;
} // Canvas::~Canvas



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
	
	Selectable *element[2] = {NULL};
	
	element[0] = new NORGate(-4, 8);
	element[1] = new NORGate(-4, -4);
	
	elements.push_back(element[0]);
	elements.push_back(element[1]);
	
	#define num_wires 20
	WireNode *wires[num_wires] = {NULL};
	
	// Output nodes
	wires[0] = new WireNode(4,10);
	wires[1] = new WireNode(4,-2);
	
	// Extended output nodes
	wires[2] = new WireNode(6,10);
	wires[3] = new WireNode(6,-2);
	wires[0]->ConnectOutput(wires[2]);
	wires[1]->ConnectOutput(wires[3]);
	
	// Center-pointing output nodes
	wires[4] = new WireNode(6,8);
	wires[5] = new WireNode(6,0);
	wires[2]->ConnectOutput(wires[4]);
	wires[3]->ConnectOutput(wires[5]);
	
	// Crossing nodes
	wires[6] = new WireNode(-6,0);
	wires[7] = new WireNode(-6,8);
	wires[4]->ConnectOutput(wires[6]);
	wires[5]->ConnectOutput(wires[7]);
	
	// From cross to input nodes
	wires[8] = new WireNode(-6,-1);
	wires[9] = new WireNode(-6,9);
	wires[6]->ConnectOutput(wires[8]);
	wires[7]->ConnectOutput(wires[9]);
	
	// From inputs
	wires[10] = new WireNode(-8,-1);
	wires[11] = new WireNode(-8,9);
	wires[8]->ConnectOutput(wires[10]);
	wires[9]->ConnectOutput(wires[11]);
	
	// To output pins
	wires[12] = new WireNode(8,10);
	wires[13] = new WireNode(8,-2);
	wires[2]->ConnectOutput(wires[12]);
	wires[3]->ConnectOutput(wires[13]);
	
	// To input nodes
	wires[14] = new WireNode(-4,-1);
	wires[15] = new WireNode(-4,9);
	wires[8]->ConnectOutput(wires[14]);
	wires[9]->ConnectOutput(wires[15]);
	
	// Other input nodes
	wires[16] = new WireNode(-4,11);
	wires[17] = new WireNode(-4,-3);
	wires[18] = new WireNode(-8,11);
	wires[19] = new WireNode(-8,-3);
	
	wires[18]->ConnectOutput(wires[16]);
	wires[19]->ConnectOutput(wires[17]);
	
	int i;
	for (i = 0; i < num_wires; i++) {
		elements.push_back(wires[i]);
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



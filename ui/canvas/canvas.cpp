#include "ui/canvas.h"

using namespace gator::ui;


Canvas::Canvas(Widget *parent) :
BlitWidget(parent)
{
	SetScale(7);
	SetOffsetX(0);
	SetOffsetY(0);
	
	grid = new Grid();
	
	drag_started = false;
	box_select_started = false;
	
	
	// XXX: Testing...
	
	int X, Y;
	int x, y;
	for (X = 0; X < 22; X++) {
		for (Y = 0; Y < 22; Y++) {
			x = X*20;
			y = Y*20;
			
			Selectable *element[2] = {NULL};
			
			element[0] = new NORGate(x+-4, y+8);
			element[1] = new NORGate(x+-4, y+-4);
			
			elements.push_back(element[0]);
			elements.push_back(element[1]);
			
			#define num_wires 20
			WireNode *wires[num_wires] = {NULL};
			
			// Output nodes
			wires[0] = new WireNode(x+4, y+10);
			wires[1] = new WireNode(x+4,y+-2);
			
			// Extended output nodes
			wires[2] = new WireNode(x+6,y+10);
			wires[3] = new WireNode(x+6,y+-2);
			wires[0]->ConnectOutput(wires[2]);
			wires[1]->ConnectOutput(wires[3]);
			
			// Center-pointing output nodes
			wires[4] = new WireNode(x+6,y+8);
			wires[5] = new WireNode(x+6,y+0);
			wires[2]->ConnectOutput(wires[4]);
			wires[3]->ConnectOutput(wires[5]);
			
			// Crossing nodes
			wires[6] = new WireNode(x+-6,y+0);
			wires[7] = new WireNode(x+-6,y+8);
			wires[4]->ConnectOutput(wires[6]);
			wires[5]->ConnectOutput(wires[7]);
			
			// From cross to input nodes
			wires[8] = new WireNode(x+-6,y+-1);
			wires[9] = new WireNode(x+-6,y+9);
			wires[6]->ConnectOutput(wires[8]);
			wires[7]->ConnectOutput(wires[9]);
			
			// From inputs
			wires[10] = new WireNode(x+-8,y+-1);
			wires[11] = new WireNode(x+-8,y+9);
			wires[8]->ConnectOutput(wires[10]);
			wires[9]->ConnectOutput(wires[11]);
			
			// To output pins
			wires[12] = new WireNode(x+8,y+10);
			wires[13] = new WireNode(x+8,y+-2);
			wires[2]->ConnectOutput(wires[12]);
			wires[3]->ConnectOutput(wires[13]);
			
			// To input nodes
			wires[14] = new WireNode(x+-4,y+-1);
			wires[15] = new WireNode(x+-4,y+9);
			wires[8]->ConnectOutput(wires[14]);
			wires[9]->ConnectOutput(wires[15]);
			
			// Other input nodes
			wires[16] = new WireNode(x+-4,y+11);
			wires[17] = new WireNode(x+-4,y+-3);
			wires[18] = new WireNode(x+-8,y+11);
			wires[19] = new WireNode(x+-8,y+-3);
			
			wires[18]->ConnectOutput(wires[16]);
			wires[19]->ConnectOutput(wires[17]);
			
			int i;
			for (i = 0; i < num_wires; i++) {
				elements.push_back(wires[i]);
			}
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
} // Canvas::~Canvas



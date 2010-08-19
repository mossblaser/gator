#include "ui/elements/wirenode.h"

using namespace gator::ui;

WireNode::WireNode(int x, int y) :
Selectable(x, y, AND_GATE_WIDTH, AND_GATE_HEIGHT)
{
	input = NULL;
} // WireNode::WireNode


WireNode::~WireNode(void)
{
	// Do nothing...
} // WireNode::~WireNode


bool
WireNode::Draw(Canvas *canvas)
{
	if (canvas == NULL)
		return false;
	
	SDL_Surface *surf   = canvas->GetSurf();
	Pallet      *pallet = canvas->GetPallet();
	if (surf == NULL || pallet == NULL)
		return false;
	
	Uint32 colour = IsSelected() ? pallet->GetWireSel()
	                             : pallet->GetWire();
	
	int x = canvas->XS(this->x);
	int y = canvas->YS(this->y);
	
	int num_outputs = 0;
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		WireNode *output = (*node);
		num_outputs++;
		
		lineColor(surf, x, y,
		          canvas->XS(output->x), canvas->YS(output->y), colour);
	}
	
	if (num_outputs > 1) {
		filledCircleColor(surf, x, y, canvas->GetScale()/2, colour);
	}
	
	return true;
} // WireNode::Draw


int
WireNode::GetX(void)
{
	// XXX: Borked
	return this->x;
	int x;
	int min = this->x;
	
	if (input) {
		x = input->GetX();
		if (x < min) min = x;
	}
	
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		x = (*node)->GetX();
		if (x < min) min = x;
	}
	
	return min;
} // WireNode::GetX


int
WireNode::GetY(void)
{
	// XXX: Borked
	return this->y;
	int y;
	int min = this->y;
	
	if (input) {
		y = input->GetY();
		if (y < min) min = y;
	}
	
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		y = (*node)->GetY();
		if (y < min) min = y;
	}
	
	return min;
} // WireNode::GetY


int
WireNode::GetWidth(void)
{
	// XXX: Borked
	return 0;
	int node_r;
	int l = GetX();
	int r = this->x;
	
	if (input) {
		node_r = input->GetWidth() + input->GetX();
		if (node_r > r) r = node_r;
	}
	
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		node_r = (*node)->GetWidth() + (*node)->GetX();
		if (node_r > r) r = node_r;
	}
	
	return r - l;
} // WireNode::GetWidth


int
WireNode::GetHeight(void)
{
	// XXX: Borked
	return 0;
	int node_b;
	int t = GetY();
	int b = this->y;
	
	if (input) {
		node_b = input->GetHeight() + input->GetY();
		if (node_b > b) b = node_b;
	}
	
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		node_b = (*node)->GetHeight() + (*node)->GetY();
		if (node_b > b) b = node_b;
	}
	
	return b - t;
} // WireNode::GetHeight


void
WireNode::ConnectInput(WireNode *input)
{
	this->input = input;
} // WireNode::ConnectInput


void
WireNode::ConnectOutput(WireNode *output)
{
	output->ConnectInput(this);
	outputs.push_back(output);
} // WireNode::ConnectOutput


void
WireNode::DisconnectOutput(WireNode *output)
{
	// Assumption: The output is connected exactly once
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		if ((*node) == output) {
			outputs.erase(node);
			return;
		}
	}
} // WireNode::DisconnectOutput

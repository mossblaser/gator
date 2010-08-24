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
	
	if (input != NULL) {
		lineColor(surf, x, y,
		          canvas->XS(input->x), canvas->YS(input->y), colour);
	}
	
	int num_outputs = 0;
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		WireNode *output = (*node);
		if (++num_outputs > 1) {
			filledCircleColor(surf, x, y, canvas->GetScale()/2, colour);
			break;
		}
	}
	
	return true;
} // WireNode::Draw


#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))


int
WireNode::GetX(void)
{
	if (input != NULL)
		return MIN(this->x, input->x);
	else
		return this->x;
} // WireNode::GetX


int
WireNode::GetY(void)
{
	if (input != NULL)
		return MIN(this->y, input->y);
	else
		return this->y;
} // WireNode::GetY


int
WireNode::GetWidth(void)
{
	if (input != NULL)
		return abs(this->x - input->x);
	else
		return 0;
} // WireNode::GetWidth


int
WireNode::GetHeight(void)
{
	if (input != NULL)
		return abs(this->y - input->y);
	else
		return 0;
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


bool
WireNode::IsAtPoint(int x, int y)
{
	if (input == NULL)
		return false;
	
	int l = (input->GetX() < this->GetX()) ? input->GetX() : this->GetX();
	int r = (input->GetX() > this->GetX()) ? input->GetX() : this->GetX();
	int t = (input->GetY() < this->GetY()) ? input->GetY() : this->GetY();
	int b = (input->GetY() > this->GetY()) ? input->GetY() : this->GetY();
	
	if (x < l || x > r || y < t || y > b) {
		printf("no: outside rect %d, %d: l%d, r%d, t%d, b%d\n", x, y, l,r,t,b);
		return false;
	}
	
	if (l == r || t == b) {
		printf("yes: 0 W/H\n");
		return true;
	}
	
	return false;
} // WireNode::IsAtPoint

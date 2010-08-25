#include "ui/elements/wirenode.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))


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
WireNode::HasBlob(void)
{
	int num_connections = input != NULL ? 1 : 0;
	
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		if (++num_connections > 2) {
			return true;
		}
	}
	
	return false;
} // WireNode::HasBlob


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
	
	Uint32 line_colour = IsSelected() && input && input->IsSelected()
	                     ? pallet->GetWireSel()
	                     : pallet->GetWire();
	
	int x = canvas->XS(this->x);
	int y = canvas->YS(this->y);
	
	if (input != NULL) {
		lineColor(surf, x, y,
		          canvas->XS(input->x), canvas->YS(input->y), line_colour);
	}
	
	int blob_radius = canvas->GetScale() / WIRE_NODE_BLOB_SIZE_DIVISOR;
	
	if (HasBlob()) {
		filledCircleColor(surf, x, y, blob_radius, colour);
	} else {
		blob_radius /= 2;
	}
	
	if (IsSelected())
		circleColor(surf, x, y, blob_radius + WIRE_NODE_SELECT_RING_SPACING,
		            colour);
	
	return true;
} // WireNode::Draw


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
	if (IsNodeAtPoint(x,y))
		return true;
	
	if (input != NULL
	    && !input->IsNodeAtPoint(x,y)
	    && IsPointOnInputLine(x, y))
		return true;
	
	std::vector<WireNode*>::iterator node;
	for (node = outputs.begin(); node != outputs.end(); ++node) {
		WireNode *output = (*node);
		
		if (!output->IsNodeAtPoint(x,y) && output->IsPointOnInputLine(x,y))
			return true;
	}
	
	return false;
} // WireNode::IsAtPoint


bool
WireNode::IsPointOnInputLine(int x, int y)
{
	if (input == NULL)
		return false;
	
	int l = GetX();
	int r = l + GetWidth();
	int t = GetY();
	int b = t + GetHeight();
	
	// Outside the rectangle this wire segment occupies
	if (x < l || x > r || y < t || y > b) {
		return false;
	}
	
	// This wire is orthogonal
	if (l == r || t == b) {
		return true;
	}
	
	
	// The wire is not orthogonal
	
	// Not on an end point, find the distance of the point from the line
	// p1: This point
	double p1x = (double) this->x;
	double p1y = (double) this->y;
	
	// p2: The point at the other end of the line
	double p2x = (double) input->x;
	double p2y = (double) input->y;
	
	// p3: The point where the user clicked
	double p3x = (double) x;
	double p3y = (double) y;
	
	double q = (p2y - p1y) / (p2x - p1x);
	
	// For equations in the form y = bx + a these are the values of a for
	//   l1: The line between p1 and p2
	//   l2: The line perpendicular to l1 going through p3
	double l1a = p1y - (q * p1x);
	double l2a = p3y + (p3x / q);
	
	// p4: The point of intersection between l1 and l2
	double p4x = (l2a - l1a) / (q + (1.0/q));
	double p4y = (q * p4x) + p1y - (q * p1x);
	
	if ((pow(p3x - p4x, 2) + pow(p3y - p4y, 2)) <= 0.5)
		return true;
	
	return false;
} // WireNode::IsPointOnInputLine


bool
WireNode::IsNodeAtPoint(int x, int y)
{
	return (this->x == x && this->y == y);
} // WireNode::IsNodeAtPoint



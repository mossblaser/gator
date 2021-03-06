#include "ui/element.h"

using namespace gator::ui;


Element::Element(int x, int y, int width, int height) :
x(x),
y(y),
width(width),
height(height)
{
	// Do nothing...
} // Element::Element


Element::~Element(void)
{
	// Do nothing...
} // Element::~Element


void Element::Move(int relx, int rely)
{
	SetX(GetX() + relx);
	SetY(GetY() + rely);
} // Element::Move


void Element::SetX(int x) {this->x = x;}
void Element::SetY(int y) {this->y = y;}
void Element::SetWidth(int width) {this->width = width;}
void Element::SetHeight(int height) {this->height = height;}

int Element::GetX(void) {return x;}
int Element::GetY(void) {return y;}
int Element::GetWidth(void) {return width;}
int Element::GetHeight(void) {return height;}


bool
Element::IsAtPoint(int x, int y)
{
	return (x >= GetX() && x <= (GetX() + GetWidth()))
	       && (y >= GetY() && y <= (GetY() + GetHeight()));
} // Element::IsAtPoint


bool
Element::IsInRect(int x1, int y1, int x2, int y2)
{
	int l = GetX();
	int r = l + GetWidth();
	int t = GetY();
	int b = t + GetHeight();
	
	return (l >= x1 && l <= x2 && r >= x1 && r <= x2
	        && t >= y1 && t <= y2 && b >= y1 && b <= y2);
} // Element::IsInRect

#include "ui/widget.h"

using namespace gator::ui;


Widget::Widget(Widget *parent) :
parent(parent)
{
	surf = NULL;
	pallet = NULL;
	x = y = width = height = 0;
} // Widget::Widget


Widget::~Widget(void)
{
	// Do nothing
} // Widget::~Widget


bool
Widget::NeedsRedraw(void)
{
	return needs_redraw;
} // Widget::NeedsRedraw


void
Widget::NeedsRedraw(bool value)
{
	needs_redraw = value;
} // Widget::NeedsRedraw


SDL_Surface *
Widget::GetSurf(void)
{
	if (surf)
		return surf;
	else if (GetParent())
		return GetParent()->GetSurf();
	else
		return NULL;
}


void
Widget::SetSurf(SDL_Surface *surf)
{
	this->surf = surf;
}


Widget *
Widget::GetParent(void)
{
	return parent;
}


void
Widget::SetParent(Widget *parent)
{
	this->parent = parent;
}


void
Widget::SetPallet(Pallet *pallet)
{
	this->pallet = pallet;
} // Widget::SetPallet


Pallet *
Widget::GetPallet(void)
{
	return (pallet ? pallet : (parent ? parent->GetPallet() : NULL));
} // Widget::GetPallet

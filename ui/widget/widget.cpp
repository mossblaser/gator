#include "ui/widget.h"

using namespace gator::ui;


Widget::Widget(Widget *parent, SDL_Surface *surf) :
parent(parent),
surf(surf)
{
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
	return surf;
}


Pallet *
Widget::GetPallet(void)
{
	return parent ? parent->GetPallet() : NULL;
} // Widget::GetPallet

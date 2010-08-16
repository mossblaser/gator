#include <SDL.h>
#include <SDL_gfxPrimitives.h>
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
}



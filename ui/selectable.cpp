#include "ui/selectable.h"

using namespace gator::ui;


Selectable::Selectable(int x, int y, int width, int height) :
Element(x,y,width,height)
{
	selected = false;
} // Selectable::Selectable


Selectable::~Selectable(void)
{
	// Do nothing...
} // Selectable::~Selectable


bool
Selectable::IsSelected(void)
{
	return selected;
} // Selectable::IsSelected


void
Selectable::SetSelected(bool state)
{
	selected = state;
} // Selectable::SetSelected


void
Selectable::ToggleSelection(int x, int y)
{
	SetSelected(!IsSelected());
} // Selectable::ToggleSelection

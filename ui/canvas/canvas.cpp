#include "ui/canvas.h"

using namespace gator::ui;


Canvas::Canvas(Widget *parent) :
BlitWidget(parent)
{
	SetScale(7);
	SetOffsetX(0);
	SetOffsetY(0);
	
	grid = new Grid();
	
	design = NULL;
	drag_started = false;
	box_select_started = false;
} // Canvas::Canvas


Canvas::~Canvas(void)
{
	// Do nothing...
} // Canvas::~Canvas


void
Canvas::SetDesign(Design *design)
{
	this->design = design;
} // Canvas::SetDesign


Design *
Canvas::GetDesign(void)
{
	return design;
} // Canvas::GetDesign


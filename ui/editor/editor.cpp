#include "ui/editor.h"

using namespace gator::ui;


Editor::Editor(Widget *parent) :
Widget(parent),
canvas(this)
{
	design = NULL;
	SetupSize();
	SetupPosition();
} // Editor::Editor


Editor::~Editor(void)
{
	delete GetCanvas();
} // Editor::~Editor


Canvas *
Editor::GetCanvas(void)
{
	return &canvas;
} // Editor::GetCanvas


void
Editor::SetDesign(Design *design)
{
	this->design = design;
	canvas.SetDesign(design);
} // Editor::SetDesign


Design *
Editor::GetDesign(void)
{
	return design;
} // Editor::GetDesign

#include "ui/editor.h"

using namespace gator::ui;


Editor::Editor(Widget *parent) :
Widget(parent)
{
	canvas = new Canvas(this);
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
	return canvas;
} // Editor::GetCanvas

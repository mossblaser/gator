#include "ui/editor.h"

using namespace gator::ui;


Editor::Editor(Widget *parent) :
Widget(parent)
{
	canvas = NULL;
} // Editor::Editor


Editor::~Editor(void)
{
	// Do nothing...
} // Editor::~Editor


void
Editor::SetCanvas(Canvas *canvas)
{
	this->canvas = canvas;
	
	if (this->canvas)
		this->canvas->SetParent(this);
	
	SetupPosition();
	SetupSize();
} // Editor::SetCanvas


Canvas *
Editor::GetCanvas(void)
{
	return canvas;
} // Editor::SetCanvas

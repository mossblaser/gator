#include "ui/editor.h"

using namespace gator::ui;


void
Editor::SetupSize(void)
{
	Canvas *canvas = GetCanvas();
	if (canvas)
		canvas->SetSize(GetWidth(), GetHeight() - EDITOR_TOOLBOX_HEIGHT);
} // Editor::SetupSize


void Editor::SetWidth(int w)  {Widget::SetWidth(w); SetupSize();}
void Editor::SetHeight(int h){Widget::SetHeight(h); SetupSize();}
void Editor::SetSize(int w, int h){Widget::SetSize(w, h); SetupSize();}


void
Editor::SetupPosition(void)
{
	Canvas *canvas = GetCanvas();
	if (canvas) {
		canvas->SetX(GetX());
		canvas->SetY(GetY());
	}
} // Editor::SetupPosition


void Editor::SetX(int x)  {Widget::SetX(x); SetupPosition();}
void Editor::SetY(int y)  {Widget::SetY(y); SetupPosition();}

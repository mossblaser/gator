#include "ui/editorcontainer.h"

using namespace gator::ui;


void
EditorContainer::SetupSize(void)
{
	EditorContainer::Layout layout = GetLayout();
	
	int num_editors = editors.size();
	
	int size = ((layout == EditorContainer::LAYOUT_VSPLIT)
	            ? GetWidth() : GetHeight())
	           / (num_editors ? num_editors : 1);
	
	std::list<Editor *>::iterator editor_i;
	for (editor_i = editors.begin(); editor_i != editors.end(); ++editor_i) {
		if (layout == EditorContainer::LAYOUT_TAB) {
			(*editor_i)->SetSize(GetWidth(), GetHeight());
		} else {
			(*editor_i)->SetSize(
				(layout == EditorContainer::LAYOUT_VSPLIT) ? size : GetWidth(),
				(layout == EditorContainer::LAYOUT_HSPLIT) ? size : GetHeight()
			);
		}
	}
} // EditorContainer::SetupSize


void
EditorContainer::SetWidth(int w)   {
	Widget::SetWidth(w);
	SetupSize();
	SetupPosition();
} // EditorContainer::SetWidth


void
EditorContainer::SetHeight(int h) {
	Widget::SetHeight(h);
	SetupSize();
	SetupPosition();
} // EditorContainer::SetHeight


void
EditorContainer::SetSize(int w, int h) {
	Widget::SetSize(w, h);
	SetupSize();
	SetupPosition();
} // EditorContainer::SetSize


void
EditorContainer::SetupPosition(void)
{
	EditorContainer::Layout layout = GetLayout();
	
	int num_editors = editors.size();
	
	int size = ((layout == EditorContainer::LAYOUT_VSPLIT)
	            ? GetWidth() : GetHeight())
	           / (num_editors ? num_editors : 1);
	
	int position = (layout == EditorContainer::LAYOUT_VSPLIT)
	               ? GetX() : GetY();
	
	std::list<Editor *>::iterator editor_i;
	for (editor_i = editors.begin(); editor_i != editors.end(); ++editor_i) {
		if (layout == EditorContainer::LAYOUT_TAB) {
			(*editor_i)->SetX(GetX());
			(*editor_i)->SetY(GetY());
		} else {
			(*editor_i)->SetX(
				(layout == EditorContainer::LAYOUT_VSPLIT) ? position : GetX());
			(*editor_i)->SetY(
				(layout == EditorContainer::LAYOUT_HSPLIT) ? position : GetY());
			position += size;
		}
	}
	
} // EditorContainer::SetupPosition


void EditorContainer::SetX(int x)  {Widget::SetX(x); SetupPosition();}
void EditorContainer::SetY(int y)  {Widget::SetY(y); SetupPosition();}


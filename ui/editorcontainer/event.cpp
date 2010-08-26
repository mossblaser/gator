#include "ui/editorcontainer.h"

using namespace gator::ui;


void
EditorContainer::MoveFocusToPoint(int x, int y)
{
	if (GetLayout() == EDITOR_CONTAINER_LAYOUT_TAB)
		return;
	
	std::list<Editor *>::iterator editor_i;
	for (editor_i = editors.begin(); editor_i != editors.end(); ++editor_i) {
		Editor *editor = (*editor_i);
		int l = editor->GetX();
		int r = l + editor->GetWidth();
		int t = editor->GetY();
		int b = t + editor->GetHeight();
		if (x >= l && x < r && y >= t && y < b) {
			SetFocus(editor);
			return;
		}
	}
	
	SetFocus(NULL);
	return;
} // EditorContainer::MoveFocusToPoint


bool
EditorContainer::OnButtonDown(int x, int y,
                     bool left, bool right, bool middle)
{
	if (x < GetX() || x > GetX() + GetWidth() - 1
	    || y < GetY() || y > GetY() + GetHeight() - 1) {
		MoveFocusToPoint(x, y);
		return false;
	}
	
	MoveFocusToPoint(x, y);
	
	Editor *editor = GetFocus();
	if (editor && editor->OnButtonDown(x, y, left, right, middle))
		return true;
	
	return false;
} // EditorContainer::OnButtonDown


bool
EditorContainer::OnButtonUp(int x, int y,
                   bool left, bool right, bool middle)
{
	if (x < GetX() || x > GetX() + GetWidth() - 1
	    || y < GetY() || y > GetY() + GetHeight() - 1) {
		MoveFocusToPoint(x, y);
		return false;
	}
	
	MoveFocusToPoint(x, y);
	
	Editor *editor = GetFocus();
	if (editor && editor->OnButtonUp(x, y, left, right, middle))
		return true;
	
	return false;
} // EditorContainer::OnButtonUp


bool
EditorContainer::OnMouseMove(int x, int y, int relx, int rely,
                    bool left, bool right, bool middle)
{
	if (x < GetX() || x > GetX() + GetWidth() - 1
	    || y < GetY() || y > GetY() + GetHeight() - 1) {
		if (!left && !right && !middle)
			MoveFocusToPoint(x, y);
		return false;
	}
	
	if (!left && !right && !middle)
		MoveFocusToPoint(x, y);
	
	Editor *editor = GetFocus();
	if (editor && editor->OnMouseMove(x, y, relx, rely, left, right, middle))
		return true;
	
	return false;
} // EditorContainer::OnMouseMove


bool
EditorContainer::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	Editor *editor = GetFocus();
	if (editor && editor->OnKeyUp(sym, mod, unicode))
		return true;
	
	return false;
} // EditorContainer::OnMouseMove



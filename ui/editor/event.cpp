#include "ui/editor.h"

using namespace gator::ui;


bool
Editor::OnButtonDown(int x, int y,
                     bool left, bool right, bool middle)
{
	if (x < GetX() || x > GetX() + GetWidth() - 1
	    || y < GetY() || y > GetY() + GetHeight() - 1)
		return false;
	
	Canvas *canvas = GetCanvas();
	if (canvas && canvas->OnButtonDown(x, y, left, right, middle))
		return true;
	
	return false;
} // Editor::OnButtonDown


bool
Editor::OnButtonUp(int x, int y,
                   bool left, bool right, bool middle)
{
	if (x < GetX() || x > GetX() + GetWidth() - 1
	    || y < GetY() || y > GetY() + GetHeight() - 1)
		return false;
	
	Canvas *canvas = GetCanvas();
	if (canvas && canvas->OnButtonUp(x, y, left, right, middle))
		return true;
	
	return false;
} // Editor::OnButtonUp


bool
Editor::OnMouseMove(int x, int y, int relx, int rely,
                    bool left, bool right, bool middle)
{
	if (x < GetX() || x > GetX() + GetWidth() - 1
	    || y < GetY() || y > GetY() + GetHeight() - 1)
		return false;
	
	Canvas *canvas = GetCanvas();
	if (canvas && canvas->OnMouseMove(x, y, relx, rely, left, right, middle))
		return true;
	
	return false;
} // Editor::OnMouseMove


bool
Editor::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	Canvas *canvas = GetCanvas();
	if (canvas && canvas->OnKeyUp(sym, mod, unicode))
		return true;
	
	return false;
} // Editor::OnMouseMove


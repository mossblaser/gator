#include <SDL.h>
#include "ui/pallet.h"
#include "ui/widget.h"

using namespace gator::ui;

bool Widget::OnButtonDown(int x, int y, bool left, bool right, bool middle)
{return false;}
bool Widget::OnButtonUp  (int x, int y, bool left, bool right, bool middle)
{return false;}
bool Widget::OnMouseMove (int x, int y, int relx, int rely,
                          bool left, bool right, bool middle)
{return false;}
bool Widget::OnKeyDown   (SDLKey key, SDLMod mod, Uint16 unicode)
{return false;}
bool Widget::OnKeyUp     (SDLKey key, SDLMod mod, Uint16 unicode)
{return false;}


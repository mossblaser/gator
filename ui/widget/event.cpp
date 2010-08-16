#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/widget.h"

using namespace gator::ui;

void Widget::OnButtonDown(int x, int y, bool left, bool right, bool middle) {}
void Widget::OnButtonUp  (int x, int y, bool left, bool right, bool middle) {}
void Widget::OnMouseMove (int x, int y, int relx, int rely,
                          bool left, bool right, bool middle)               {}
void Widget::OnKeyDown   (SDLKey key, SDLMod mod, Uint16 unicode)           {}
void Widget::OnKeyUp     (SDLKey key, SDLMod mod, Uint16 unicode)           {}


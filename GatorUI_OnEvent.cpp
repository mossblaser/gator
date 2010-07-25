#include "GatorUI.h"

void
GatorUI::OnQuit()
{
	running = false;
}

void
GatorUI::OnButtonDown(int x, int y, bool left, bool right, bool middle)
{
	if (x >= canvas_x && x < canvas_x + canvas->GetW()
	    && y >= canvas_y && y < canvas_y + canvas->GetH())
		canvas->OnButtonDown(x - canvas_x, y - canvas_y, left, right, middle);
}

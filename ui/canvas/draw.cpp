#include "ui/canvas.h"

using namespace gator::ui;


bool
Canvas::Draw(void)
{
	if (GetSurf() == NULL || GetPallet() == NULL)
		return false;
	
	// Draw the background
	boxColor(GetSurf(), 0, 0, GetWidth(), GetHeight(), GetPallet()->GetBG());
	
	grid->Draw(this);
	
	std::vector<Selectable*>::iterator element;
	for (element = elements.begin();
	     element != elements.end();
	     ++element) {
		int x1 = (*element)->GetX();
		int x2 = x1 + (*element)->GetWidth();
		int y1 = (*element)->GetY();
		int y2 = y1 + (*element)->GetHeight();
		
		if (IsRectOnScreen(x1, y1, x2, y2))
			(*element)->Draw(this);
	}
	
	if (box_select_started) {
		rectangleColor(GetSurf(), XS(box_select_start_x), YS(box_select_start_y),
		               XS(box_select_end_x), YS(box_select_end_y),
		               GetPallet()->GetSelectBoxBorder());
	}
	
	NeedsRedraw(true);
	return BlitWidget::Draw();
} // Canvas::Draw

#include "ui/canvas.h"

using namespace gator::ui;


Pallet *
Canvas::GetPallet(void)
{
	return pallet;
} // Canvas::GetPallet


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
	
	NeedsRedraw(true);
	return BlitWidget::Draw();
} // Canvas::Draw

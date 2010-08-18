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
	
	std::vector<Element*>::iterator element;
	for (element = elements.begin();
	     element != elements.end();
	     ++element) {
		(*element)->Draw(this);
	}
	
	NeedsRedraw(true);
	return BlitWidget::Draw();
} // Canvas::Draw

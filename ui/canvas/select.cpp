#include "ui/canvas.h"

using namespace gator::ui;


void
Canvas::OnSelect(int x, int y, bool drag)
{
	bool shift = SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT);
	
	int grid_x = SX(x);
	int grid_y = SY(y);
	
	if (!drag) {
		/* Select behaviour when not dragging:
		 *  > Click to select the element under the cursor.
		 *  > Click empty space to deselect everything
		 *  > Shift+click to add an element to the selection
		 *  > Shift+click to toggle the selection on an element.
		 */
		std::vector<Selectable*>::iterator element;
		for (element = elements.begin(); element != elements.end(); ++element) {
			if ((*element)->IsAtPoint(grid_x, grid_y)) {
				if (!shift)
					(*element)->SetSelected(true);
				else
					(*element)->SetSelected(!(*element)->IsSelected());
			} else {
				if (!shift)
					(*element)->SetSelected(false);
			}
		}
	} else {
		/* Select behaviour when dragging:
		 *  > Drag from an non-selected element to select and drag that one element.
		 *  > Drag from a selected element to drag all selected elements.
		 */
		bool element_at_point = false;
		bool new_selection = false;
		std::vector<Selectable*>::iterator element;
		
		for (element = elements.begin(); element != elements.end(); ++element) {
			if ((*element)->IsAtPoint(grid_x, grid_y)) {
				element_at_point = true;
				if (!(*element)->IsSelected()) {
					new_selection = true;
				}
			}
		}
		
		if (new_selection || !element_at_point) {
			for (element = elements.begin(); element != elements.end(); ++element) {
				if ((*element)->IsAtPoint(grid_x, grid_y)) {
					(*element)->SetSelected(true);
				} else if (!element_at_point || !shift) {
					(*element)->SetSelected(false);
				}
			}
		}
	}
} // Canvas::OnSelect


void
Canvas::OnDrag(int x, int y, int relx, int rely, bool end_drag)
{
	static bool drag_started = false;
	static int accx = 0;
	static int accy = 0;
	
	if (!end_drag) {
		accx += relx;
		accy += rely;
		
		int movx = accx / GetScale();
		int movy = accy / GetScale();
		
		if (movx || movy) {
			if (!drag_started)
				OnSelect(x - accx, y - accy, true);
			
			accx -= movx * GetScale();
			accy -= movy * GetScale();
			
			std::vector<Selectable*>::iterator element;
			for (element = elements.begin();
			     element != elements.end();
			     ++element) {
				if ((*element)->IsSelected()) {
					(*element)->Move(movx, movy);
				}
			}
			drag_started = true;
		}
	} else {
		if (!drag_started) {
			OnSelect(x, y, false);
		}
		drag_started = false;
		accx = 0;
		accy = 0;
	}
} // Canvas::OnDrag


bool
Canvas::OnDelete(void)
{
	bool deleted = false;
	
	std::vector<Selectable*>::iterator element;
	for (element = elements.begin(); element != elements.end(); ++element) {
		while(true) {
			Selectable *elem = *element;
			if (elem->IsSelected()) {
				element = elements.erase(element);
				delete elem;
				deleted = true;
				continue;
			}
			break;
		}
	}
	
	return deleted;
} // Canvas::OnDelete

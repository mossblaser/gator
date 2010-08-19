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
		bool new_selection = false;
		std::vector<Selectable*>::iterator element;
		
		for (element = elements.begin(); element != elements.end(); ++element) {
			if ((*element)->IsAtPoint(grid_x, grid_y)) {
				if (!(*element)->IsSelected()) {
					new_selection = true;
				}
			}
		}
		
		if (new_selection) {
			for (element = elements.begin(); element != elements.end(); ++element) {
				if ((*element)->IsAtPoint(grid_x, grid_y)) {
					(*element)->SetSelected(true);
				} else {
					(*element)->SetSelected(false);
				}
			}
		}
	}
} // Canvas::OnSelect


void
Canvas::OnDrag(int relx, int rely, bool end_drag)
{
	static int accx = 0;
	static int accy = 0;
	
	if (!end_drag) {
		accx += relx;
		accy += rely;
		
		int movx = accx / GetScale();
		int movy = accy / GetScale();
		
		if (movx || movy) {
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
		}
		
	} else {
		accx = 0;
		accy = 0;
	}
} // Canvas::OnDrag

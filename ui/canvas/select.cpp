#include "ui/canvas.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

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
					(*element)->ToggleSelection(grid_x, grid_y);
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


// XXX: Needs cleanup
void
Canvas::OnDrag(int x, int y, int relx, int rely, bool end_drag)
{
	static bool drag_started = false;
	static int accx = 0;
	static int accy = 0;
	
	bool shift = SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT);
	
	if (!end_drag) {
		accx += relx;
		accy += rely;
		
		int movx = accx / GetScale();
		int movy = accy / GetScale();
		
		if (movx || movy) {
			bool elements_selected = false;
			if (!shift) {
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
						elements_selected = true;
					}
				}
			}
			
			// Nothing was selected so this is a box select not a move operation
			if (!elements_selected) {
				box_select_started = true;
				if (!drag_started) {
					box_select_start_x = SX(x) - movx;
					box_select_start_y = SY(y) - movy;
				}
			}
			
			drag_started = true;
		}
		
		if (drag_started) {
			box_select_end_x = SX(x);
			box_select_end_y = SY(y);
		}
	} else {
		if (!drag_started) {
			OnSelect(x, y, false);
		}
		if (box_select_started) {
			SelectRect(MIN(box_select_start_x, box_select_end_x),
			           MIN(box_select_start_y, box_select_end_y),
			           MAX(box_select_start_x, box_select_end_x),
			           MAX(box_select_start_y, box_select_end_y));
			box_select_started = false;
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
			if (element == elements.end())
				return deleted;
			
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


void
Canvas::SelectAll(void)
{
	std::vector<Selectable*>::iterator element;
	for (element = elements.begin(); element != elements.end(); ++element) {
		(*element)->SetSelected(true);
	}
} // Canvas::SelectAll


void
Canvas::SelectNone(void)
{
	std::vector<Selectable*>::iterator element;
	for (element = elements.begin(); element != elements.end(); ++element) {
		(*element)->SetSelected(false);
	}
} // Canvas::SelectNone


void
Canvas::SelectRect(int x1, int y1, int x2, int y2)
{
	bool shift = SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT);
	
	if (!shift)
		SelectNone();
	
	// XXX: This is hyper-inefficient
	int x, y;
	std::vector<Selectable*>::iterator element;
	for (element = elements.begin(); element != elements.end(); ++element) {
		for (x = x1; x <= x2; x++) {
			for (y = y1; y <= y2; y++) {
				if (!((*element)->IsSelected())
				    && (*element)->IsAtPoint(x, y)) {
					(*element)->SetSelected(true);
				}
			}
		}
	}
} // Canvas::SelectRect

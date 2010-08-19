#include "ui/canvas.h"

using namespace gator::ui;


bool
Canvas::OnButtonDown(int x, int y, bool left, bool right, bool middle)
{
	return false;
} // Canvas::OnButtonDown


bool
Canvas::OnButtonUp(int x, int y, bool left, bool right, bool middle)
{
	if (left && !right && !middle) {
		if (!drag_started)
			OnSelect(x, y, false);
		
		// End drag
		drag_started = false;
		OnDrag(0, 0, true);
		return true;
	}
	
	return false;
} // Canvas::OnButtonUp


bool
Canvas::OnMouseMove(int x, int y, int relx, int rely,
                    bool left, bool right, bool middle)
{
	// Do nothing if mouse not over this widget
	if (x >= GetWidth() || y >= GetHeight())
		return false;
	
	// Zoom when right button held and dragging up/down
	static int accumulated_y = 0;
	if (right && !left && !middle) {
		accumulated_y += rely;
		int distance = accumulated_y / ZOOM_SENSITIVITY;
		if (distance != 0) {
			accumulated_y -= distance * ZOOM_SENSITIVITY;
			OnZoom(-distance);
		}
		return true;
	} else {
		accumulated_y = 0;
	}
	
	// Pan when dragging with middle button held
	if (middle && !right && !left) {
		OnPan(relx, rely);
		return true;
	}
	
	// Drag/Select on drag with left button
	if (left && !right && !middle) {
		if (!drag_started)
			OnSelect(x, y, true);
		
		OnDrag(relx, rely, false);
		drag_started = true;
		return true;
	}
	
	// The event was not handled.
	return false;
} // Canvas::OnMouseMove


void
Canvas::OnPan(int relx, int rely)
{
	SetOffsetX(GetOffsetX() + relx);
	SetOffsetY(GetOffsetY() + rely);
} // Canvas::OnPan


void
Canvas::OnZoom(int change)
{
	int old_scale = GetScale();
	int new_scale = old_scale + change;
	
	if (SetScale(new_scale)) {
		// Centre view
		SetOffsetX((GetOffsetX() * new_scale) / old_scale);
		SetOffsetY((GetOffsetY() * new_scale) / old_scale);
	}
} // Canvas::OnZoom

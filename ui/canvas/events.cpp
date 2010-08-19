#include "ui/canvas.h"

using namespace gator::ui;


bool
Canvas::OnMouseMove(int x, int y, int relx, int rely,
                    bool left, bool right, bool middle)
{
	if (x < GetX() || y < GetY()
	    || x >= GetX() + GetWidth()
	    || y >= GetY() + GetHeight())
		return false;
	
	static int accumulated_y = 0;
	if (right && !left && !middle) {
		accumulated_y += rely;
		int distance = accumulated_y / ZOOM_SENSITIVITY;
		if (distance != 0) {
			accumulated_y -= distance * ZOOM_SENSITIVITY;
			OnZoom(-distance);
		}
	} else {
		accumulated_y = 0;
	}
	
	
	if (middle && !right && !left) {
		OnPan(relx, rely);
		return true;
	}
	
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

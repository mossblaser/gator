#include "ui/canvas.h"

using namespace gator::ui;


const int Canvas::GetScale(void)   {return scale;}
const int Canvas::GetOffsetX(void) {return offset_x;}
const int Canvas::GetOffsetY(void) {return offset_y;}

bool
Canvas::SetScale(int new_scale)
{
	if (new_scale > 0 && new_scale < 20) {
		scale = new_scale;
		return true;
	} else {
		return false;
	}
} // Canvas::GetScale

bool
Canvas::SetOffsetX(int new_offset_x)
{
	offset_x = new_offset_x;
	return true;
} // Canvas::SetOffsetX

bool
Canvas::SetOffsetY(int new_offset_y)
{
	offset_y = new_offset_y;
	return true;
} // Canvas::SetOffsetY


const int
Canvas::XS(int x)
{
	int pixels = x * GetScale();
	int centre = GetOffsetX() + (GetWidth() / 2);
	return centre + pixels;
} // Canvas::XS


const int
Canvas::YS(int y)
{
	int pixels = y * GetScale();
	int centre = GetOffsetY() + (GetHeight() / 2);
	return centre + pixels;
} // Canvas::YS


const int
Canvas::XSC(int x)
{
	int l = GetX();
	int r = l + GetWidth();
	int val = Canvas::XS(x);
	return ((val >= l) ? ((val < r) ? val
	                                : r)
	                   : (l - 1));
} // Canvas::XSC


const int
Canvas::YSC(int y)
{
	int t = GetY();
	int b = t + GetHeight();
	int val = Canvas::YS(y);
	return ((val >= t) ? ((val < b) ? val
	                                : b)
	                   : (t - 1));
} // Canvas::YSC


const int
Canvas::SX(int x)
{
	// De-centralise the coordinate
	x -= GetOffsetX() + (GetWidth() / 2);
	
	return (x + ((x<0?-1:1) * (GetScale() / 2))) / GetScale();
} // Canvas::SX


const int
Canvas::SY(int y)
{
	// De-centralise the coordinate
	y -= GetOffsetY() + (GetHeight() / 2);
	
	return (y + ((y<0?-1:1) * GetScale() / 2)) / GetScale();
} // Canvas::SY


const bool
Canvas::IsRectOnScreen(int x1, int y1, int x2, int y2)
{
	// Get the screen boundaries
	int t = SY(0);
	int b = SY(GetHeight());
	int l = SX(0);
	int r = SX(GetWidth());
	
	bool inside_x = (x1 >= l && x1 < r)    // x1 in width
	                || (x2 >= l && x2 < r) // x2 in width
	                || (x1 < l && x2 > l)  // x crosses left edge
	                || (x2 < l && x1 > l)  // ditto
	                || (x1 < r && x2 > r)  // x crosses right edge
	                || (x2 < r && x1 > r); // ditto
	
	bool inside_y = (y1 >= t && y1 < b)    // y1 in height
	                || (y2 >= t && y2 < b) // y2 in height
	                || (y1 < t && y2 > t)  // y crosses top edge
	                || (y2 < t && y1 > t)  // ditto
	                || (y1 < b && y2 > b)  // y crosses bottom edge
	                || (y2 < b && y1 > b); // ditto
	
	return inside_x && inside_y;
} // Canvas::IsRectOnScreen

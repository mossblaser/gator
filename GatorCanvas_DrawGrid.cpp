#include "GatorCanvas.h"


void
GatorCanvas::DrawGrid(void)
{
	// Draw background
	boxColor(surf, XPClip(XToXP(0)), YPClip(YToYP(0)),
	         XPClip(XToXP(GetMaxX())), YPClip(YToYP(GetMaxY())),
	         pallet->background);
	
	int x, y;
	
	if (scale > 4) {
		// Draw Minor Gridlines
		for (x = 0; x < GetMaxX(); x++)
			vlineColor(surf, (XToXP(x)),
			           YPClip(YToYP(0)), YPClip(YToYP(GetMaxY())),
			           pallet->grid_minor);
		for (y = 0; y < GetMaxY(); y++)
			hlineColor(surf, XPClip(XToXP(0)), XPClip(XToXP(GetMaxX())),
			           YPClip(YToYP(y)),
			           pallet->grid_minor);
	}
	
	// Draw Major Gridlines
	for (x = 0; x < GetMaxX(); x+=MAJOR_GRID_LINES)
		vlineColor(surf, XPClip(XToXP(x)),
		           YPClip(YToYP(0)), YPClip(YToYP(GetMaxY())),
		           pallet->grid_major);
	for (y = 0; y < GetMaxY(); y+=MAJOR_GRID_LINES)
		hlineColor(surf, XPClip(XToXP(0)), XPClip(XToXP(GetMaxX())),
		           YPClip(YToYP(y)),
		           pallet->grid_major);
}

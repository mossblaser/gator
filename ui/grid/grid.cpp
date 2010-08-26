#include "ui/grid.h"

using namespace gator::ui;


Grid::Grid(void) :
Element(0,0,0,0)
{
	// Do nothing...
} // Grid::Grid


Grid::~Grid(void)
{
	// Do nothing...
} // Grid::~Grid


void
Grid::HLine(SDL_Surface *surf, int x1, int x2, int y, Uint32 colour)
{
	hlineColor(surf, x1, x2, y, colour);
} // Grid::HLine


void
Grid::VLine(SDL_Surface *surf, int x, int y1, int y2, Uint32 colour)
{
	vlineColor(surf, x, y1, y2, colour);
} // Grid::VLine


bool
Grid::Draw(Canvas *canvas)
{
	if (canvas == NULL)
		return false;
	
	SDL_Surface *surf   = canvas->GetSurf();
	Pallet      *pallet = canvas->GetPallet();
	
	if (surf == NULL || pallet == NULL)
		return false;
	
	// Get grid coordinates just off the edges of the screen
	int l = canvas->SX(0) - 1;
	int r = canvas->SX(canvas->GetWidth()) + 1;
	int t = canvas->SY(0) - 1;
	int b = canvas->SY(canvas->GetHeight()) + 1;
	
	// Counters
	int x, y;
	
	// Pixel positions of edges of the screen.
	int x1 = 0;
	int x2 = canvas->GetWidth();
	int y1 = 0;
	int y2 = canvas->GetHeight();
	
	Uint32 colour = pallet->GetCanvasGridMin();
	
	// Minor Gridlines
	if (canvas->GetScale() >= GRID_MINOR_MINIMUM_SCALE) {
		for (y = t; y <= b; y++) {
			HLine(surf, x1, x2, canvas->YS(y), colour);
		}
		for (x = l; x <= r; x++) {
			VLine(surf, canvas->XS(x), y1, y2, colour);
		}
		
		colour = pallet->GetCanvasGridMaj();
	}
	
	// Major Gridlines
	for (y = t; y <= b; y++) {
		if (y % GRID_MAJOR_INTERVAL == 0)
			HLine(surf, x1, x2, canvas->YS(y), colour);
	}
	
	for (x = l; x <= r; x++) {
		if (x % GRID_MAJOR_INTERVAL == 0)
			VLine(surf, canvas->XS(x), y1, y2, colour);
	}
	
	return true;
} // Grid::Draw

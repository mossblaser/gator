#ifndef GRID_H
#define GRID_H

#define GRID_MINOR_MINIMUM_SCALE 3
#define GRID_MAJOR_INTERVAL 5

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"

namespace gator {
	namespace ui {
		
		class Grid : public Element
		{
			private:
				void HLine(SDL_Surface *surf, int x1, int x2, int y, Uint32 colour);
				void VLine(SDL_Surface *surf, int x, int y1, int y2, Uint32 colour);
			
			public:
				virtual bool Draw(Canvas *canvas);
		}; // class element
		
	} // namespace ui
} // namespace gator


#endif


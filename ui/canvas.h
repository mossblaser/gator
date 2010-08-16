#ifndef CANVAS_H
#define CANVAS_H

#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/blit_widget.h"
#include "ui/grid.h"

namespace gator {
	namespace ui {
		
		class Grid;
		
		/**
		 * An item which displays on the screen but which internally draws onto its
		 * own surface and then blits this onto the target surface on draw.
		 */
		class Canvas : public BlitWidget {
			protected:
				Pallet *pallet;
				Grid *grid;
			
			public:
				Canvas(Widget *parent, SDL_Surface *surf);
				~Canvas(void);
				
				virtual Pallet *GetPallet(void);
				virtual bool Draw(void);
			
			protected:
				int scale;
				int offset_x;
				int offset_y;
			
			public:
				const int GetScale(void);
				const int GetOffsetX(void);
				const int GetOffsetY(void);
				
				bool SetScale(int new_scale);
				bool SetOffsetX(int new_offset_x);
				bool SetOffsetY(int new_offset_y);
				
				/** Turn an X coordinate on the grid into a screen coordinate. */
				const int XS (int x);
				
				/** Turn a Y coordinate on the grid into a screen coordinate. */
				const int YS (int y);
				
				
				/**
				 * Turn an X coordinate on the grid into a screen coordinate limited
				 * to a one-pixel radius of the canvas' screen area.
				 */
				const int XSC(int x);
				
				/**
				 * Turn a Y coordinate on the grid into a screen coordinate limited
				 * to a one-pixel radius of the canvas' screen area.
				 */
				const int YSC(int y);
				
				/** Turn a screen coordinate into an X coordinate on the grid. */
				const int SX (int x);
				
				/** Turn a screen coordinate into a Y coordinate on the grid. */
				const int SY (int y);
				
				
				/** Check if a rectangle would be visible anywhere on the screen. */
				const bool RectOnScreen(int x1, int y1, int x2, int y2);
			
		}; // class BlitWidget
		
	} // namespace ui
} // namespace gator

#endif


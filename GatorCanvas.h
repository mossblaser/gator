#ifndef GATOR_CANVAS_H
#define GATOR_CANVAS_H

class GatorCanvas;

#include <list>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "GatorPallet.h"
#include "GatorElement.h"
#include "GatorVideoOptions.h"

/* The multiple of which a gridline must be to be a major one. */
#define MAJOR_GRID_LINES 5

/* The maximum size of the grid in blocks. */
#define GRID_SIZE 5000

class GatorCanvas {
	protected:
		SDL_Surface *surf;
		
		int          w;
		int          h;
		int          scale;
		
		/* The x and y offsets in pixels for the viewport (visible area) */
		int          viewport_xp;
		int          viewport_yp;
		
		GatorPallet *pallet;
		
		void         DrawGrid(void);
		
		std::list<GatorElement *> elements;
	
	public:
		GatorCanvas(void);
		~GatorCanvas(void);
		
		bool         SetScale(int new_scale);
		int          GetScale();
		
		bool         SetSize(int new_w, int new_h);
		
		void         SetPallet(GatorPallet *new_pallet);
		GatorPallet *GetPallet();
		
		bool         Draw(SDL_Surface *target_surf, int x, int y);
		
		inline int   XToXP(int x) { return (x * scale) - viewport_xp; };
		inline int   YToYP(int y) { return (y * scale) - viewport_yp; };
		
		inline int   XPClip(int xp) { return (xp < 0) ? -1
		                                     : ((xp > w) ? w + 1 : xp); };
		inline int   YPClip(int yp) { return (yp < 0) ? -1
		                                     : ((yp > h) ? h + 1 : yp); };
		
		int          GetMaxX(void);
		int          GetMaxY(void);
		
		void         AddElement(GatorElement *new_element);
};

#endif

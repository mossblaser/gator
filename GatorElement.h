#ifndef GATOR_ELEMENT_H
#define GATOR_ELEMENT_H

class GatorElement;

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "GatorPallet.h"
#include "GatorCanvas.h"

class GatorElement {
	protected:
		SDL_Surface *surf;
		
		int          x;
		int          y;
		int          w;
		int          h;
		
		int          selected;
		
		GatorCanvas *canvas;
	
	public:
		GatorElement(GatorCanvas *new_canvas);
		
		void         SetX(int new_x);
		int          GetX();
		void         SetY(int new_y);
		int          GetY();
		
		void         Selected(bool new_selected);
		bool         Selected(void);
		
		bool         Draw(SDL_Surface *surf);
};

#endif

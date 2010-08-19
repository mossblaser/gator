#ifndef ELEMENTS_AND_H
#define ELEMENTS_AND_H

#define AND_GATE_WIDTH 8
#define AND_GATE_HEIGHT 4

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"
#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class ANDGate : public Selectable
		{
			public:
				ANDGate(int x, int y);
				virtual ~ANDGate(void);
				
				virtual inline int GetWidth(void){ return AND_GATE_WIDTH; };
				virtual inline int GetHeight(void){ return AND_GATE_HEIGHT; };
				virtual bool Draw(Canvas *canvas);
		}; // class ANDGate
		
	} // namespace ui
} // namespace gator


#endif




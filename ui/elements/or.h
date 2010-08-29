#ifndef ELEMENTS_OR_H
#define ELEMENTS_OR_H

#define OR_GATE_WIDTH 8
#define OR_GATE_HEIGHT 4

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"
#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class ORGate : public Selectable
		{
			public:
				ORGate(int x, int y);
				virtual ~ORGate(void);
				
				virtual inline int GetWidth(void){ return OR_GATE_WIDTH; };
				virtual inline int GetHeight(void){ return OR_GATE_HEIGHT; };
				virtual bool Draw(Canvas *canvas);
		}; // class ORGate
		
	} // namespace ui
} // namespace gator


#endif


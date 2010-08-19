#ifndef ELEMENTS_NOR_H
#define ELEMENTS_NOR_H

#define NOR_GATE_WIDTH 8
#define NOR_GATE_HEIGHT 4

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"
#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class NORGate : public Selectable
		{
			public:
				NORGate(int x, int y);
				virtual ~NORGate(void);
				
				virtual inline int GetWidth(void){ return AND_GATE_WIDTH; };
				virtual inline int GetHeight(void){ return AND_GATE_HEIGHT; };
				virtual bool Draw(Canvas *canvas);
		}; // class NORGate
		
	} // namespace ui
} // namespace gator


#endif



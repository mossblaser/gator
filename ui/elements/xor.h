#ifndef ELEMENTS_XOR_H
#define ELEMENTS_XOR_H

#define XOR_GATE_WIDTH 8
#define XOR_GATE_HEIGHT 4

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"
#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class XORGate : public Selectable
		{
			public:
				XORGate(int x, int y);
				virtual ~XORGate(void);
				
				virtual inline int GetWidth(void){ return AND_GATE_WIDTH; };
				virtual inline int GetHeight(void){ return AND_GATE_HEIGHT; };
				virtual bool Draw(Canvas *canvas);
		}; // class XORGate
		
	} // namespace ui
} // namespace gator


#endif


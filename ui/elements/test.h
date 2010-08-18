#ifndef ELEMENTS_TEST_H
#define ELEMENTS_TEST_H

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"
#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class TestElement : public Element, public Selectable
		{
			public:
				TestElement(int x, int y);
				virtual ~TestElement(void);
				
				virtual bool Draw(Canvas *canvas);
		}; // class TestElement
		
	} // namespace ui
} // namespace gator


#endif



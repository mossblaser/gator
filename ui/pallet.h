#ifndef PALLET_H
#define PALLET_H

#include <SDL.h>
#include <SDL_gfxPrimitives.h>

namespace gator {
	namespace ui {
		
		class Pallet
		{
			private:
				Uint32 BG;
				Uint32 CanvasBG;
				Uint32 CanvasGridMaj;
				Uint32 CanvasGridMin;
				Uint32 Element;
				Uint32 ElementSel;
			
			public:
				Pallet(void);
				~Pallet(void);
				
				const Uint32 GetBG(void);
				const Uint32 GetCanvasBG(void);
				const Uint32 GetCanvasGridMaj(void);
				const Uint32 GetCanvasGridMin(void);
				const Uint32 GetElement(void);
				const Uint32 GetElementSel(void);
				
		}; // class Pallet
		
	} // namespace ui
} // namespace gator


#endif

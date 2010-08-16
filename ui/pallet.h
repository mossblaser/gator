#ifndef PALLET_H
#define PALLET_H

#include <SDL.h>
#include <SDL_gfxPrimitives.h>

namespace gator {
	namespace ui {
		
		class Pallet
		{
			public:
				Pallet(void);
				~Pallet(void);
				
				const Uint32 GetBG(void);
				const Uint32 GetCanvasBG(void);
				const Uint32 GetCanvasGridMaj(void);
				const Uint32 GetCanvasGridMin(void);
			
			private:
				Uint32 BG;
				Uint32 CanvasBG;
				Uint32 CanvasGridMaj;
				Uint32 CanvasGridMin;
				
		}; // class Pallet
		
	} // namespace ui
} // namespace gator


#endif

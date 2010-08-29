#ifndef EDITOR_H
#define EDITOR_H

#define EDITOR_TOOLBOX_HEIGHT 18

#include <vector>

#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/widget.h"
#include "ui/canvas.h"


namespace gator {
	namespace ui {
		
		class Editor : public Widget {
			private:
				Design *design;
				Canvas canvas;
				
			protected:
				void SetupSize(void);
				void SetupPosition(void);
			
			public:
				Editor(Widget *parent);
				virtual ~Editor(void);
				
				virtual Canvas *GetCanvas(void);
				
				virtual bool Draw(void);
				
				virtual void SetX(int width);
				virtual void SetY(int height);
				
				virtual void SetWidth(int width);
				virtual void SetHeight(int height);
				virtual void SetSize(int width, int height);
				
				virtual void SetDesign(Design *design);
				virtual Design *GetDesign(void);
			
			public:
				virtual bool OnButtonDown(int x, int y,
				                          bool left, bool right, bool middle);
				virtual bool OnButtonUp(int x, int y,
				                        bool left, bool right, bool middle);
				virtual bool OnMouseMove (int x, int y, int relx, int rely,
				                          bool left, bool right, bool middle);
				virtual bool OnKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);
				
		}; // class Editor
		
	} // namespace ui
} // namespace gator

#endif



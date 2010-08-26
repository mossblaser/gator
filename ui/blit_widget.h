#ifndef BLIT_WIDGET_H
#define BLIT_WIDGET_H

#include "ui/widget.h"

namespace gator {
	namespace ui {
		class BlitWidget;
		
		/**
		 * An item which displays on the screen but which internally draws onto its
		 * own surface and then blits this onto the target surface on draw.
		 */
		class BlitWidget : public Widget {
			private:
				SDL_Surface *surf;
				SDL_Surface *target_surf;
				
				void SetupScreen(void);
			
			public:
				BlitWidget(Widget *parent);
				virtual ~BlitWidget(void);
				
				virtual void SetSurf(SDL_Surface *surf);
				virtual SDL_Surface *GetSurf(void);
				virtual SDL_Surface *GetTargetSurf(void);
				
				virtual bool Draw(void);
				
				virtual void SetWidth(int width);
				virtual void SetHeight(int height);
				virtual void SetSize(int width, int height);
		}; // class BlitWidget
		
	} // namespace ui
} // namespace gator

#endif

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
			
			public:
				BlitWidget(Widget *parent, SDL_Surface *surf);
				virtual ~BlitWidget(void);
				
				virtual SDL_Surface *GetSurf(void);
				virtual SDL_Surface *GetTargetSurf(void);
				
				virtual bool Draw(void);
		}; // class BlitWidget
		
	} // namespace ui
} // namespace gator

#endif

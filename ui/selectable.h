#ifndef SELECTABLE_H
#define SELECTABLE_H

#include "ui/element.h"

namespace gator {
	namespace ui {
		
		class Selectable : public Element
		{
			private:
				bool selected;
			
			public:
				Selectable(int x, int y, int width, int height);
				virtual ~Selectable(void);
				
				virtual bool IsSelected(void);
				virtual void SetSelected(bool state);
		}; // class Selectable
		
	} // namespace ui
} // namespace gator


#endif


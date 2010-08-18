#ifndef SELECTABLE_H
#define SELECTABLE_H

namespace gator {
	namespace ui {
		
		class Selectable
		{
			private:
				bool selected;
			
			public:
				Selectable(void);
				virtual ~Selectable(void);
				
				virtual bool IsSelected(void);
				virtual void SetSelected(bool state);
		}; // class Selectable
		
	} // namespace ui
} // namespace gator


#endif


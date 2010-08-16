#ifndef ELEMENT_H
#define ELEMENT_H


namespace gator {
	namespace ui {
		
		class Canvas;
		class Element;
		
		class Element
		{
			public:
				virtual bool Draw(Canvas *canvas) = 0;
		}; // class Element
		
	} // namespace ui
} // namespace gator


#endif

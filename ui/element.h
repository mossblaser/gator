#ifndef ELEMENT_H
#define ELEMENT_H


namespace gator {
	namespace ui {
		
		class Canvas;
		class Element;
		
		class Element
		{
			protected:
				int x;
				int y;
				int width;
				int height;
			
			public:
				Element(int x, int y, int width, int height);
				virtual ~Element(void);
				
				virtual void Move(int relx, int rely);
				
				virtual void SetX     (int x);
				virtual void SetY     (int y);
				virtual void SetWidth (int width);
				virtual void SetHeight(int height);
				virtual int GetX(void);
				virtual int GetY(void);
				virtual int GetWidth (void);
				virtual int GetHeight(void);
				
				virtual bool IsAtPoint(int x, int y);
				virtual bool IsInRect(int x1, int y1, int x2, int y2);
				
				virtual bool Draw(Canvas *canvas) = 0;
		}; // class Element
		
	} // namespace ui
} // namespace gator


#endif

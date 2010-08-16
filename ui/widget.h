#ifndef UI_H
#define UI_H

namespace gator {
	namespace ui {
		
		class Widget;
		
		/**
		 * An item that displays on the screen.
		 */
		class Widget
		{
			protected:
				Widget      *parent;
				SDL_Surface *surf;
				
				int x, y, width, height;
			
			public:
				/**
				 * Constructor.
				 *
				 * @param parent The parent Widget.
				 * @param surf An SDL surface onto which this Widget should draw itself.
				 */
				Widget(Widget *parent, SDL_Surface *surf);
				
				/** Destructor */
				virtual ~Widget(void);
				
				/**
				 * Draw this widget onto the widget's surface.
				 */
				virtual bool Draw(void) = 0;
				
			public:
				/** Get the X coordinate of the widget  */
				virtual int GetX(void);
				
				/** Get the Y coordinate of the widget  */
				virtual int GetY(void);
				
				/** Get the width of the widget */
				virtual int GetWidth(void);
				
				/** Get the height of the widget */
				virtual int GetHeight(void);
				
				/** Set the X coordinate of the widget  */
				virtual void SetX(int x);
				
				/** Set the Y coordinate of the widget  */
				virtual void SetY(int y);
				
				/** Set the width of the widget */
				virtual void SetWidth(int width);
				
				/** Set the height of the widget */
				virtual void SetHeight(int height);
			
			public:
				/**
				 * Called when a mouse button is pressed on this widget.
				 *
				 * @param x The X-coordinate.
				 * @param y The Y-coordinate.
				 * @param left   Was the left button pressed.
				 * @param right  Was the right button pressed.
				 * @param middle Was the middle button pressed.
				 */
				virtual void OnButtonDown(int x, int y, bool left, bool right, bool middle);
				
				/**
				 * Called when a mouse button is released on this widget.
				 *
				 * @param x The X-coordinate.
				 * @param y The Y-coordinate.
				 * @param left   Was the left button pressed.
				 * @param right  Was the right button pressed.
				 * @param middle Was the middle button pressed.
				 */
				virtual void OnButtonUp  (int x, int y, bool left, bool right, bool middle);
				
				/**
				 * Called when the mouse is moved over this widget.
				 *
				 * @param x The X-coordinate.
				 * @param y The Y-coordinate.
				 * @param left   Was the left button pressed.
				 * @param right  Was the right button pressed.
				 * @param middle Was the middle button pressed.
				 */
				virtual void OnMouseMove (int x, int y, int relx, int rely,
				                          bool left, bool right, bool middle);
				
				virtual void OnKeyDown(SDLKey key, SDLMod mod, Uint16 unicode);
				virtual void OnKeyUp  (SDLKey key, SDLMod mod, Uint16 unicode);
		}; // class Widget
		
	} // namespace ui
} // namespace gator

#endif

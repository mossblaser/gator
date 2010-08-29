#ifndef EDITOR_CONTAINER_H
#define EDITOR_CONTAINER_H

#include <list>
#include "ui/editor.h"

namespace gator {
	namespace ui {
		
		class EditorContainer : public Widget {
			public:
				typedef enum Layout {
					LAYOUT_TAB,
					LAYOUT_VSPLIT,
					LAYOUT_HSPLIT,
				} Layout;
			
			private:
				std::list<Editor *> editors;
				Editor *focus;
				EditorContainer::Layout layout;
			
			public:
				EditorContainer(Widget *parent);
				virtual ~EditorContainer(void);
				
				virtual bool Draw(void);
				
				virtual void AddEditor(Editor *editor);
				virtual void RemoveEditor(Editor *editor);
				
				virtual void SetX(int x);
				virtual void SetY(int y);
				
				virtual void SetWidth(int width);
				virtual void SetHeight(int height);
				virtual void SetSize(int width, int height);
				
				virtual void SetFocus(Editor *editor);
				virtual Editor *GetFocus(void);
				
				virtual void SetLayout(EditorContainer::Layout layout);
				virtual EditorContainer::Layout GetLayout(void);
			
			protected:
				virtual void SetupSize(void);
				virtual void SetupPosition(void);
			
			protected:
				/** Set the editor at position x,y as the focused editor. */
				virtual void MoveFocusToPoint(int x, int y);
			
			public:
				virtual bool OnButtonDown(int x, int y,
				                          bool left, bool right, bool middle);
				virtual bool OnButtonUp(int x, int y,
				                        bool left, bool right, bool middle);
				virtual bool OnMouseMove (int x, int y, int relx, int rely,
				                          bool left, bool right, bool middle);
				virtual bool OnKeyUp(SDLKey key, SDLMod mod, Uint16 unicode);
				
		}; // class EditorContainer
		
	} // namespace ui
} // namespace gator

#endif



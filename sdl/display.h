#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_RESIZE_DELAY_TICKS 100

#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "sdl/video_options.h"
#include "sdl/event_handler.h"
#include "ui/widget.h"

int main(int argc, char *argv[]);

namespace gator {
	namespace sdl {
		class Display;
		
		/**
		 * The main window of the application.
		 */
		class Display : public EventHandler
		{
			private:
				int width, height;
				SDL_Surface *display;
				std::vector<gator::ui::Widget*> widgets;
				bool running;
				
				SDL_Surface *SetVideoMode(void);
			
			public:
				Display(void);
				virtual ~Display(void);
				int Main(void);
				
				int GetWidth(void);
				int GetHeight(void);
				
			public:
				bool OnInit(void);
				void OnLoop(void);
				void OnRender(void);
				void OnCleanup(void);
				
			protected:
				void OnQuit(void);
				virtual void OnButtonDown(int x, int y,
				                          bool left, bool right, bool middle);
				virtual void OnButtonUp(int x, int y,
				                        bool left, bool right, bool middle);
				virtual void OnMouseMove(int x, int y, int relx, int rely,
				                         bool left,bool right,bool middle);
				virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
				virtual void OnResize(int new_width, int new_height);
			
			protected:
				int last_resize_ticks;
				int resize_width;
				int resize_height;
				virtual void DoResize(int new_width, int new_height);
			
		}; // class Display
		
	} // namespace sdl
} // namespace gator

#endif

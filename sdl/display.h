#ifndef DISPLAY_H
#define DISPLAY_H

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
				SDL_Surface *display;
				
				std::vector<gator::ui::Widget*> widgets;
				
				bool running;
			
			public:
				Display(void);
				virtual ~Display(void);
				int Main(void);
				
			public:
				bool OnInit(void);
				void OnLoop(void);
				void OnRender(void);
				void OnCleanup(void);
				
			protected:
				void OnQuit(void);
			
		}; // class Display
		
	} // namespace sdl
} // namespace gator

#endif

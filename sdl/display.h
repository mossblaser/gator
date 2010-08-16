#ifndef DISPLAY_H
#define DISPLAY_H

#define VWIDTH  1024
#define VHEIGHT  768
#define VDEPTH    32

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
				virtual void OnQuit(void);
			
		}; // class Display
		
	} // namespace sdl
} // namespace gator

#endif

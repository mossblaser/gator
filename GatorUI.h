#ifndef GATOR_UI_H
#define GATOR_UI_H
#include <SDL.h>
#include <SDL_image.h>
#include "GatorVideoOptions.h"
#include "GatorPallet.h"
#include "GatorCanvas.h"

class GatorUI;

class GatorUI {
	private:
		bool running;
		
		SDL_Surface  *display;
		
		GatorCanvas  *canvas;
		GatorPallet  *pallet;
		GatorElement *element;
		GatorElement *element2;
	
	public:
		GatorUI();
		
		int OnExecute(void);
		
		bool OnInit(void);
		void OnEvent(SDL_Event *event);
		void OnLoop(void);
		void OnRender(void);
		void OnCleanup(void);
};

#endif

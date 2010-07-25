#ifndef GATOR_UI_H
#define GATOR_UI_H
#include <SDL.h>
#include <SDL_image.h>
#include "GatorVideoOptions.h"
#include "GatorSDLEventHandler.h"
#include "GatorPallet.h"
#include "GatorCanvas.h"

class GatorUI;

class GatorUI : public GatorSDLEventHandler {
	private:
		bool running;
		
		SDL_Surface  *display;
		
		GatorCanvas  *canvas;
		int           canvas_x;
		int           canvas_y;
		
		GatorPallet  *pallet;
		GatorElement *element;
		GatorElement *element2;
	
	public:
		GatorUI();
		
		int OnExecute(void);
		
		bool OnInit(void);
		void OnLoop(void);
		void OnRender(void);
		void OnCleanup(void);
		
		void OnQuit(void);
		void OnButtonDown(int x, int y, bool left, bool right, bool middle);
		void OnButtonUp(int x, int y, bool left, bool right, bool middle);
		void OnMouseMove(int xp, int yp, int relxp, int relyp,
		                 bool left, bool right, bool middle);
};

#endif

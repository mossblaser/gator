#include "GatorUI.h"

GatorUI::GatorUI() : GatorSDLEventHandler()
{
	canvas_x = 10;
	canvas_y = 10;
	
	running = true;
	
	display = NULL;
}

int GatorUI::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}
	
	SDL_Event event;
	
	while (running) {
		while (SDL_PollEvent(&event)) {
			OnEvent(&event);
		}
		
		OnLoop();
		OnRender();
	}
	
	OnCleanup();
	
	return 0;
}

int main(int argc, char* argv[]) {
	GatorUI theApp;
	
	return theApp.OnExecute();
}

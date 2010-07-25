/* From: http://www.sdltutorials.com/sdl-events/ */
#include "GatorSDLEventHandler.h"

GatorSDLEventHandler::GatorSDLEventHandler() {
}
GatorSDLEventHandler::~GatorSDLEventHandler() {
	//Do nothing
}
void GatorSDLEventHandler::OnEvent(SDL_Event* Event) {
	switch(Event->type) {
		case SDL_ACTIVEEVENT: {
			switch(Event->active.state) {
				case SDL_APPMOUSEFOCUS: {
					if ( Event->active.gain )   OnMouseFocus();
					else				OnMouseBlur();
					break;
				}
				case SDL_APPINPUTFOCUS: {
					if ( Event->active.gain )   OnInputFocus();
					else				OnInputBlur();
					break;
				}
				case SDL_APPACTIVE: {
					if ( Event->active.gain )   OnRestore();
					else				OnMinimize();
					break;
				}
			}
			break;
		}
		case SDL_KEYDOWN: {
			OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
			break;
		}
		case SDL_KEYUP: {
			OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.unicode);
			break;
		}
		case SDL_MOUSEMOTION: {
			OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					OnButtonDown(Event->button.x,Event->button.y, true, false, false);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					OnButtonDown(Event->button.x,Event->button.y, false, true, false);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					OnButtonDown(Event->button.x,Event->button.y, false, false, true);
					break;
				}
			}
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			switch(Event->button.button) {
				case SDL_BUTTON_LEFT: {
					OnButtonUp(Event->button.x,Event->button.y, true, false, false);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					OnButtonUp(Event->button.x,Event->button.y, false, true, false);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					OnButtonUp(Event->button.x,Event->button.y, false, false, true);
					break;
				}
			}
			break;
		}
		case SDL_JOYAXISMOTION: {
			OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
			break;
		}
		case SDL_JOYBALLMOTION: {
			OnJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
			break;
		}
		case SDL_JOYHATMOTION: {
			OnJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
			break;
		}
		case SDL_JOYBUTTONDOWN: {
			OnJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
			break;
		}
		case SDL_JOYBUTTONUP: {
			OnJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
			break;
		}
		case SDL_QUIT: {
			OnQuit();
			break;
		}
		case SDL_SYSWMEVENT: {
			//Ignore
			break;
		}
		case SDL_VIDEORESIZE: {
			OnResize(Event->resize.w,Event->resize.h);
			break;
		}
		case SDL_VIDEOEXPOSE: {
			OnExpose();
			break;
		}
		default: {
			OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
			break;
		}
	}
}
void GatorSDLEventHandler::OnInputFocus() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnInputBlur() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnMouseFocus() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnMouseBlur() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnMouseWheel(bool Up, bool Down) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnButtonDown(int mX, int mY, bool left, bool right, bool middle) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnButtonUp(int mX, int mY, bool left, bool right, bool middle) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnJoyButtonDown(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnJoyButtonUp(Uint8 which,Uint8 button) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnMinimize() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnRestore() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnResize(int w,int h) {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnExpose() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnQuit() {
	//Pure virtual, do nothing
}
void GatorSDLEventHandler::OnUser(Uint8 type, int code, void* data1, void* data2) {
	//Pure virtual, do nothing
}


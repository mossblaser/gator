/* From: http://www.sdltutorials.com/sdl-events/ */

#ifndef GATOR_SDL_EVENT_HANDLER_H
#define GATOR_SDL_EVENT_HANDLER_H
#include <SDL.h>

class GatorSDLEventHandler {
	protected:
		GatorSDLEventHandler();
		virtual ~GatorSDLEventHandler();
		virtual void OnEvent(SDL_Event* Event);
		virtual void OnInputFocus();
		virtual void OnInputBlur();
		virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
		virtual void OnMouseFocus();
		virtual void OnMouseBlur();
		virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
		virtual void OnMouseWheel(bool Up, bool Down);  //Not implemented
		virtual void OnButtonDown(int mX, int mY, bool left, bool right, bool middle);
		virtual void OnButtonUp(int mX, int mY, bool left, bool right, bool middle);
		virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
		virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
		virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
		virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
		virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
		virtual void OnMinimize();
		virtual void OnRestore();
		virtual void OnResize(int w,int h);
		virtual void OnExpose();
		virtual void OnQuit();
		virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};

#endif

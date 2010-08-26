#include "sdl/display.h"
#include "ui/editorcontainer.h"
#include "ui/editor.h"
#include "ui/pallet.h"

using namespace gator::sdl;

bool
Display::OnInit(void)
{
	width = VWIDTH;
	height = VHEIGHT;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	display = SetVideoMode();
	if (display == NULL) return false;
	
	int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if ((IMG_Init(flags) & flags) != flags) return false;
	
	// XXX: Testing
	gator::ui::Pallet *pallet = new gator::ui::Pallet();
	
	gator::ui::Editor *editor1 = new gator::ui::Editor(NULL);
	gator::ui::Editor *editor2 = new gator::ui::Editor(NULL);
	
	gator::ui::EditorContainer *container = new gator::ui::EditorContainer(NULL);
	container->SetSurf(display);
	container->SetPallet(pallet);
	container->SetX(0);
	container->SetY(0);
	container->SetSize(VWIDTH, VHEIGHT);
	
	container->AddEditor(editor1);
	container->AddEditor(editor2);
	container->SetLayout(gator::ui::EDITOR_CONTAINER_LAYOUT_VSPLIT);
	container->SetFocus(editor1);
	
	widgets.push_back(container);
	// XXX: End Testing
	
	return true;
} // Display::OnInit


SDL_Surface *
Display::SetVideoMode(void)
{
	return SDL_SetVideoMode(GetWidth(), GetHeight(), VDEPTH,
	                        SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
}

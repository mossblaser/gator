#include "sdl/display.h"

// XXX: For testing...
#include "ui/design.h"
#include "ui/editorcontainer.h"
#include "ui/editor.h"
#include "ui/pallet.h"
#include "ui/selectable.h"
#include "ui/elements/and.h"
#include "ui/elements/or.h"
#include "ui/elements/nor.h"
#include "ui/elements/xor.h"
#include "ui/elements/wirenode.h"


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
	using namespace gator::ui;
	Design *design = new Design();
	
	int X, Y;
	int x, y;
	for (X = 0; X < 22; X++) {
		for (Y = 0; Y < 22; Y++) {
			x = X*20;
			y = Y*20;
			
			Selectable *element[2] = {NULL};
			
			element[0] = new NORGate(x+-4, y+8);
			element[1] = new NORGate(x+-4, y+-4);
			
			design->add(element[0]);
			design->add(element[1]);
			
			#define num_wires 20
			WireNode *wires[num_wires] = {NULL};
			
			// Output nodes
			wires[0] = new WireNode(x+4, y+10);
			wires[1] = new WireNode(x+4,y+-2);
			
			// Extended output nodes
			wires[2] = new WireNode(x+6,y+10);
			wires[3] = new WireNode(x+6,y+-2);
			wires[0]->ConnectOutput(wires[2]);
			wires[1]->ConnectOutput(wires[3]);
			
			// Center-pointing output nodes
			wires[4] = new WireNode(x+6,y+8);
			wires[5] = new WireNode(x+6,y+0);
			wires[2]->ConnectOutput(wires[4]);
			wires[3]->ConnectOutput(wires[5]);
			
			// Crossing nodes
			wires[6] = new WireNode(x+-6,y+0);
			wires[7] = new WireNode(x+-6,y+8);
			wires[4]->ConnectOutput(wires[6]);
			wires[5]->ConnectOutput(wires[7]);
			
			// From cross to input nodes
			wires[8] = new WireNode(x+-6,y+-1);
			wires[9] = new WireNode(x+-6,y+9);
			wires[6]->ConnectOutput(wires[8]);
			wires[7]->ConnectOutput(wires[9]);
			
			// From inputs
			wires[10] = new WireNode(x+-8,y+-1);
			wires[11] = new WireNode(x+-8,y+9);
			wires[8]->ConnectOutput(wires[10]);
			wires[9]->ConnectOutput(wires[11]);
			
			// To output pins
			wires[12] = new WireNode(x+8,y+10);
			wires[13] = new WireNode(x+8,y+-2);
			wires[2]->ConnectOutput(wires[12]);
			wires[3]->ConnectOutput(wires[13]);
			
			// To input nodes
			wires[14] = new WireNode(x+-4,y+-1);
			wires[15] = new WireNode(x+-4,y+9);
			wires[8]->ConnectOutput(wires[14]);
			wires[9]->ConnectOutput(wires[15]);
			
			// Other input nodes
			wires[16] = new WireNode(x+-4,y+11);
			wires[17] = new WireNode(x+-4,y+-3);
			wires[18] = new WireNode(x+-8,y+11);
			wires[19] = new WireNode(x+-8,y+-3);
			
			wires[18]->ConnectOutput(wires[16]);
			wires[19]->ConnectOutput(wires[17]);
			
			int i;
			for (i = 0; i < num_wires; i++) {
				design->add(wires[i]);
			}
		}
	}
	using namespace gator::sdl;
	
	
	gator::ui::Pallet *pallet = new gator::ui::Pallet();
	
	gator::ui::Editor *editor1 = new gator::ui::Editor(NULL);
	gator::ui::Editor *editor2 = new gator::ui::Editor(NULL);
	
	editor1->SetDesign(design);
	editor2->SetDesign(design);
	
	gator::ui::EditorContainer *container = new gator::ui::EditorContainer(NULL);
	container->SetSurf(display);
	container->SetPallet(pallet);
	container->SetX(0);
	container->SetY(0);
	container->SetSize(VWIDTH, VHEIGHT);
	
	container->AddEditor(editor1);
	container->AddEditor(editor2);
	container->SetLayout(gator::ui::EditorContainer::LAYOUT_VSPLIT);
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

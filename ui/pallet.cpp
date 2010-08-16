#include "ui/pallet.h"

using namespace gator::ui;


Pallet::Pallet(void)
{
	BG            = 0x333333FF;
	CanvasBG      = 0x333333FF;
	CanvasGridMaj = 0x555555FF;
	CanvasGridMin = 0x444444FF;
} // Pallet::Pallet


Pallet::~Pallet(void)
{
	// Do nothing...
} // Pallet::~Pallet


const Uint32 Pallet::GetBG(void)            {return BG;}
const Uint32 Pallet::GetCanvasBG(void)      {return CanvasBG;}
const Uint32 Pallet::GetCanvasGridMaj(void) {return CanvasGridMaj;}
const Uint32 Pallet::GetCanvasGridMin(void) {return CanvasGridMin;}

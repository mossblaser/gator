#include "ui/pallet.h"

using namespace gator::ui;


Pallet::Pallet(void)
{
	BG              = 0x222222FF;
	CanvasBG        = 0x333333FF;
	CanvasGridMaj   = 0x555555FF;
	CanvasGridMin   = 0x444444FF;
	Element         = 0xAAAAAAFF;
	ElementSel      = 0xFFAA00FF;
	Wire            = 0xAAAAAAFF;
	WireSel         = 0xFFAA00FF;
	ToolboxBG       = 0x666666FF;
	ToolboxBorder   = 0x888888FF;
	SelectBoxBorder = 0xFFAA00FF;
} // Pallet::Pallet


Pallet::~Pallet(void)
{
	// Do nothing...
} // Pallet::~Pallet


const Uint32 Pallet::GetBG(void)              {return BG;}
const Uint32 Pallet::GetCanvasBG(void)        {return CanvasBG;}
const Uint32 Pallet::GetCanvasGridMaj(void)   {return CanvasGridMaj;}
const Uint32 Pallet::GetCanvasGridMin(void)   {return CanvasGridMin;}
const Uint32 Pallet::GetElement(void)         {return Element;}
const Uint32 Pallet::GetElementSel(void)      {return ElementSel;}
const Uint32 Pallet::GetWire(void)            {return Wire;}
const Uint32 Pallet::GetWireSel(void)         {return WireSel;}
const Uint32 Pallet::GetToolboxBG(void)       {return ToolboxBG;}
const Uint32 Pallet::GetToolboxBorder(void)   {return ToolboxBorder;}
const Uint32 Pallet::GetSelectBoxBorder(void) {return SelectBoxBorder;}

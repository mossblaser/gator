#ifndef GATOR_PALLET_H
#define GATOR_PALLET_H
#include <SDL.h>

struct GatorPallet;

struct GatorPallet {
	Uint32 background;
	Uint32 grid_major;
	Uint32 grid_minor;
	Uint32 element_normal;
	Uint32 element_selected;
};

#endif

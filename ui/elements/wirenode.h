#ifndef ELEMENTS_WIRE_NODE_H
#define ELEMENTS_WIRE_NODE_H

#define WIRE_NODE_BLOB_SIZE_DIVISOR 3
#define WIRE_NODE_SELECT_RING_SPACING 2

#include <vector>

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "ui/pallet.h"
#include "ui/canvas.h"
#include "ui/element.h"
#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class WireNode : public Selectable
		{
			public:
				WireNode(int x, int y);
				virtual ~WireNode(void);
				
				virtual int GetX(void);
				virtual int GetY(void);
				virtual int GetWidth(void);
				virtual int GetHeight(void);
				
				virtual bool Draw(Canvas *canvas);
			
			private:
				WireNode *input;
				std::vector<WireNode*> outputs;
				
				virtual bool HasBlob(void);
			
			public:
				virtual bool IsAtPoint(int x, int y);
			private:
				virtual bool IsNodeAtPoint(int x, int y);
				virtual bool IsPointOnInputLine(int x, int y);
			
			public:
				virtual void ConnectInput(WireNode *input);
				
				virtual void ConnectOutput(WireNode *output);
				virtual void DisconnectOutput(WireNode *output);
		}; // class WireNode
		
	} // namespace ui
} // namespace gator


#endif



#ifndef DESIGN_H
#define DESIGN_H


#include <vector>

#include "ui/selectable.h"

namespace gator {
	namespace ui {
		
		class Design {
			private:
				std::vector<Selectable*> elements;
			
			public:
				Design(void);
				~Design(void);
				
				typedef std::vector<Selectable*>::iterator iterator;
				
				Design::iterator begin(void);
				Design::iterator end(void);
				Design::iterator erase(Design::iterator i);
				void add(Selectable *s);
		}; // class Design
		
	} // namespace ui
} // namespace gator

#endif


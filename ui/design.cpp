#include "ui/design.h"

using namespace gator::ui;


Design::Design(void)
{
	// Do nothing...
} // Design::Design


Design::~Design(void)
{
	// Do nothing...
} // Design::~Design


Design::iterator Design::begin(void)               { return elements.begin(); }
Design::iterator Design::end(void)                 { return elements.end(); }
Design::iterator Design::erase(Design::iterator i) { return elements.erase(i); }
void             Design::add(Selectable *s)        { elements.push_back(s); }

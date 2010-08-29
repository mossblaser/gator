#include "ui/editorcontainer.h"

using namespace gator::ui;


bool
EditorContainer::Draw(void)
{
	SDL_Surface *surf   = GetSurf();
	Pallet      *pallet = GetPallet();
	if (surf == NULL || pallet == NULL)
		return false;
	
	bool empty = true;
	
	if (GetLayout() == EditorContainer::LAYOUT_TAB) {
		Editor *editor = GetFocus();
		if (editor) {
			editor->Draw();
			empty = false;
		}
	} else {
		std::list<Editor *>::iterator editor_i;
		for (editor_i = editors.begin(); editor_i != editors.end(); ++editor_i) {
			(*editor_i)->Draw();
			empty = false;
		}
	}
	
	if (empty) {
		int l = GetX();
		int r = l + GetWidth() - 1;
		int t = GetY();
		int b = t + GetHeight() - 1;
		boxColor(surf, l ,t, r, b, pallet->GetBG());
	}
	
	return true;
} // EditorContainer::Draw


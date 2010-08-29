#include "ui/editorcontainer.h"

using namespace gator::ui;


EditorContainer::EditorContainer(Widget *parent) :
Widget(parent)
{
	focus = NULL;
	layout = EditorContainer::LAYOUT_TAB;
} // EditorContainer::EditorContainer


EditorContainer::~EditorContainer(void)
{
	// Do nothing...
} // EditorContainer::~EditorContainer


void
EditorContainer::AddEditor(Editor *editor)
{
	editor->SetParent(this);
	SetupSize();
	SetupPosition();
	editors.push_back(editor);
} // EditorContainer::AddEditor


void
EditorContainer::RemoveEditor(Editor *editor)
{
	Editor *focus = GetFocus();
	
	// Assumption: An editor is only present once
	std::list<Editor *>::iterator editor_i;
	for (editor_i = editors.begin(); editor_i != editors.end(); ++editor_i) {
		if ((*editor_i) == editor) {
			editors.erase(editor_i);
			
			if ((*editor_i) == focus)
				SetFocus(NULL);
			
			SetupSize();
			SetupPosition();
			
			return;
		}
	}
} // EditorContainer::RemoveEditor


void
EditorContainer::SetLayout(EditorContainer::Layout layout)
{
	this->layout = layout;
	SetupSize();
	SetupPosition();
} // EditorContainer::SetLayout


EditorContainer::Layout
EditorContainer::GetLayout(void)
{
	return layout;
} // EditorContainer::GetLayout


void
EditorContainer::SetFocus(Editor *editor)
{
	this->focus = editor;
} // EditorContainer::SetFocus


Editor *
EditorContainer::GetFocus(void)
{
	return focus;
} // EditorContainer::GetFocus

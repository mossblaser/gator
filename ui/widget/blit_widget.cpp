#include "ui/blit_widget.h"

using namespace gator::ui;


BlitWidget::BlitWidget(Widget *parent) :
Widget(parent)
{
	surf = NULL;
	target_surf = NULL;
} // BlitWidget::BlitWidget


BlitWidget::~BlitWidget(void)
{
	if (GetSurf())
		SDL_FreeSurface(GetSurf());
} // BlitWidget::~BlitWidget


void
BlitWidget::SetupScreen(void)
{
	if (GetSurf())
		SDL_FreeSurface(GetSurf());
	
	SDL_Surface *tmp_surf = SDL_CreateRGBSurface(SDL_HWSURFACE,
	                                             GetWidth(), GetHeight(), VDEPTH,
	                                             0,0,0,0);
	if (tmp_surf) {
		this->surf = SDL_DisplayFormat(tmp_surf);
		SDL_FreeSurface(tmp_surf);
	}
} // BlitWidget::SetupScreen


void
BlitWidget::SetSurf(SDL_Surface *surf)
{
	this->target_surf = surf;
}


SDL_Surface *
BlitWidget::GetSurf(void)
{
	return surf;
} // BlitWidget::GetSurf


SDL_Surface *
BlitWidget::GetTargetSurf(void)
{
	if (target_surf)
		return target_surf;
	else if (GetParent())
		return GetParent()->GetSurf();
	else
		return NULL;
} // BlitWidget::GetTargetSurf


bool
BlitWidget::Draw(void)
{
	if (!GetSurf() || !GetTargetSurf())
		return false;
	
	if (NeedsRedraw()) {
		SDL_Rect dest_rect;
		dest_rect.x = GetX();
		dest_rect.y = GetY();
		dest_rect.w = GetWidth();
		dest_rect.h = GetHeight();
		
		SDL_BlitSurface(GetSurf(), NULL, GetTargetSurf(), &dest_rect);
	}
	
	return true;
} // BlitWidget::Draw


void BlitWidget::SetWidth(int w)  {Widget::SetWidth(w); SetupScreen();}
void BlitWidget::SetHeight(int h){Widget::SetHeight(h); SetupScreen();}
void BlitWidget::SetSize(int w, int h){Widget::SetSize(w, h); SetupScreen();}

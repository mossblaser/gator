#include "ui/blit_widget.h"

using namespace gator::ui;


BlitWidget::BlitWidget(Widget *parent, SDL_Surface *surf) :
Widget(parent, NULL),
target_surf(surf)
{
	this->surf = NULL;
	
	SDL_Surface *tmp_surf = SDL_CreateRGBSurface(SDL_HWSURFACE,
	                                             VWIDTH, VHEIGHT, VDEPTH,
	                                             0,0,0,0);
	if (tmp_surf) {
		this->surf = SDL_DisplayFormat(tmp_surf);
		SDL_FreeSurface(tmp_surf);
	}
	
	SetWidth(VWIDTH);
	SetHeight(VHEIGHT);
} // BlitWidget::BlitWidget


BlitWidget::~BlitWidget(void)
{
	if (GetSurf())
		SDL_FreeSurface(GetSurf());
} // BlitWidget::~BlitWidget


SDL_Surface *
BlitWidget::GetSurf(void)
{
	return surf;
} // BlitWidget::GetSurf


SDL_Surface *
BlitWidget::GetTargetSurf(void)
{
	return target_surf;
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

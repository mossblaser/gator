#include "ui/widget.h"

using namespace gator::ui;


int Widget::GetX(void)      {return x;}
int Widget::GetY(void)      {return y;}
int Widget::GetWidth(void)  {return width;}
int Widget::GetHeight(void) {return height;}

void Widget::SetX(int x)           {this->x      = x;}
void Widget::SetY(int y)           {this->y      = y;}
void Widget::SetWidth(int width)   {this->width  = width;}
void Widget::SetHeight(int height) {this->height = height;}

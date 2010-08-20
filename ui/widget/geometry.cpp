#include "ui/widget.h"

using namespace gator::ui;


const int Widget::GetX(void)      {return x;}
const int Widget::GetY(void)      {return y;}
const int Widget::GetWidth(void)  {return width;}
const int Widget::GetHeight(void) {return height;}

void Widget::SetX(int x)           {this->x      = x;}
void Widget::SetY(int y)           {this->y      = y;}
void Widget::SetWidth(int width)   {this->width  = width;}
void Widget::SetHeight(int height) {this->height = height;}
void Widget::SetSize(int w, int h) {width = w; height = h;}


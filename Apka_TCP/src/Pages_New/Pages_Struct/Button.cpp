#include "Button.h"

Button::Button(RECT &Main_Rect,int X,int Y,int Width,int Lenght):
Rect{Main_Rect.left + X,Main_Rect.top + Y,Main_Rect.left + X + Lenght,Main_Rect.top + Y + Width}{}

void Button::Color_Set(int Red,int Green,int Blue)
{
    Color = CreateSolidBrush(RGB(Red,Green,Blue));
}

void Button::Text_Set(std::string Position_1,std::string Position_2,std::wstring Text_In)
{
    
}
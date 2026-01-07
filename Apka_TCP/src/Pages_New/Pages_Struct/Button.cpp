#include "Button.h"

Button::Button(RECT &Main_Rect,int X,int Y,int Width,int Lenght):
Rect{Main_Rect.left + X,Main_Rect.top + Y,Main_Rect.left + X + Lenght,Main_Rect.top + Y + Width}{}

void Button::Color_Set(int Red,int Green,int Blue)
{
    Color = CreateSolidBrush(RGB(Red,Green,Blue));
}

void Button::Text_Set(std::string Position_1,std::string Position_2,std::wstring Text_In)
{
    int Position_1_Num,Position_2_Num;
    if(Position_1 == "CENTER")
    {
       Position_1_Num = DT_CENTER;
    }
    if(Position_2 == "CENTER")
    {
        Position_2_Num = DT_VCENTER;
    }
}
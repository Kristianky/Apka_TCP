#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <windows.h>
#include <string>
class Button
{
protected:

public:
    RECT Rect;
    HBRUSH Color;
    std::wstring Text;
    Button(RECT &Main_Rect, int X, int Y, int Width, int Lenght);
    void Color_Set(int Red,int Green,int Blue);
    void Text_Set(std::string Position_1,std::string Position_2,std::wstring Text_In);
};

#endif
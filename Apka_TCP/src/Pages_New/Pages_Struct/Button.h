#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <windows.h>
#include <string>

#ifndef GET_X_LPARAM
  #define GET_X_LPARAM(lp) ( (int)(short)LOWORD(lp) )
  #define GET_Y_LPARAM(lp) ( (int)(short)HIWORD(lp) )
#endif

struct Button_Text
{
    std::wstring Data;
    int Pos_Vertical,Pos_Horizontal;
    COLORREF Text_Collor;
    HFONT Text_Style;
};
class Button
{
protected:
    int Sur_X;
    int Sur_Y;
    int Btn_Width,Btn_Lenght;
public:
    RECT Rect;
    HBRUSH Color;
    Button_Text Text;
    Button(RECT &Main_Rect, int X, int Y, int Width, int Lenght);
    void Color_Set(int Red,int Green,int Blue);
    void Text_Set(int Position_1,int Position_2,std::wstring Text_In,const COLORREF &Color_Temp);
    bool Btn_Func(HWND Main_hwnd,LPARAM lparam);
 };

#endif
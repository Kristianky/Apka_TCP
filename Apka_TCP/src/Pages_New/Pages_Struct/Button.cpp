#include "Button.h"

Button::Button(RECT &Main_Rect, int X, int Y, int Width, int Lenght) : Rect{Main_Rect.left + X, Main_Rect.top + Y, Main_Rect.left + X + Lenght, Main_Rect.top + Y + Width}
{
    Sur_X = Main_Rect.left + X;
    Sur_Y = Main_Rect.top + Y;
    Btn_Width = Width;
    Btn_Lenght = Lenght;
}

void Button::Color_Set(int Red, int Green, int Blue)
{
    Color = CreateSolidBrush(RGB(Red, Green, Blue));
}

void Button::Text_Set(int Position_1, int Position_2, std::wstring Text_In, const COLORREF &Color_Temp)
{
    Text.Text_Style = CreateFontW(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");
    Text.Pos_Horizontal = Position_1;
    Text.Pos_Vertical = Position_2;
    Text.Data = Text_In;
    Text.Text_Collor = Color_Temp;
    Btn_Clicked = false;
}

void Button::Btn_In(HWND hwnd, LPARAM lparam)
{

    bool inside = Mouse::Inside(Rect);

    if (InButt_1 != inside)
    {
        InButt_1 = inside;
        InvalidateRect(hwnd, &Rect, FALSE); // žiadne UpdateWindow
    }
    else if (InButt_1 && Mouse::Lh_Butt_Down_Status)
    {
        InvalidateRect(hwnd,&Rect,FALSE);
    }
}




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
    POINT Mouse = {GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)};

    bool inside =
        (Mouse.x > Sur_X &&
         Mouse.y > Sur_Y &&
         Mouse.x < Sur_X + Btn_Lenght &&
         Mouse.y < Sur_Y + Btn_Width);

    if (InButt_1 != inside)
    {
        InButt_1 = inside;
        InvalidateRect(hwnd, &Rect, FALSE); // žiadne UpdateWindow
    }
}

void Button::L_Btn_Down(HWND hwnd, UINT umsg, LPARAM lparam)
{
    if (umsg == WM_LBUTTONDOWN)
    {
        POINT Mouse = {GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)};

        bool inside = (Mouse.x > Sur_X &&
                       Mouse.y > Sur_Y &&
                       Mouse.x < Sur_X + Btn_Lenght &&
                       Mouse.y < Sur_Y + Btn_Width);

        if (inside)
            Btn_Clicked = true;
    }
}

void Button::L_Btn_Up(HWND hwnd, UINT umsg, LPARAM lparam)
{
    if (umsg == WM_LBUTTONUP && Btn_Clicked)
    {
        POINT Mouse = {GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)};

        bool inside = (Mouse.x > Sur_X &&
                       Mouse.y > Sur_Y &&
                       Mouse.x < Sur_X + Btn_Lenght &&
                       Mouse.y < Sur_Y + Btn_Width);

        if (inside)
        {
            Inside_Bool[1] = !Inside_Bool[1];
            InvalidateRect(hwnd, NULL, TRUE);
        }

        Btn_Clicked = false;
    }
}

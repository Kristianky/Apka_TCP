#include "Edit.h"

EditWindow::EditWindow(RECT &Main_Rect, int X, int Y, int Width, int Lenght): Rect{Main_Rect.left + X, Main_Rect.top + Y, Main_Rect.left + X + Lenght, Main_Rect.top + Y + Width}
{
    Sur_X = Main_Rect.left + X;
    Sur_Y = Main_Rect.top + Y;
    Edt_Width = Width;
    Edt_Lenght = Lenght;
}

void EditWindow::Edt_In(HWND hwnd,LPARAM lpram)
{

    bool inside = Mouse::Inside(Rect);

    if (InButt != inside)
    {
        InButt = inside;
        Mouse::Cursor = LoadCursor(NULL,IDC_IBEAM);
    }
    else 
    {
         Mouse::Cursor = LoadCursor(NULL,IDC_ARROW);
    }
}
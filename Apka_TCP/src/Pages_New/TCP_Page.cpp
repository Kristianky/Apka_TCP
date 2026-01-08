#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd):VirtualPage(hwnd)
{}
void TCPPage::Button_Create(HDC hdc)
{
    HFONT HoldFont;
    HPEN HoldPen;
    Button Butt_1(Main_Rect,Main_Rect.left,Main_Rect.top + 100,200,100);
    Butt_1.Color_Set(0,0,150);
    COLORREF Text_Color = RGB(50,0,0);
    Butt_1.Text_Set(DT_CENTER,DT_VCENTER,L"Connect",Text_Color);
    FillRect(hdc,&Butt_1.Rect,Butt_1.Color);
    HoldFont = (HFONT)SelectObject(hdc,Butt_1.Text.Text_Style);
    COLORREF oldColor = GetTextColor(hdc);
    SetTextColor(hdc,Butt_1.Text.Text_Collor);
    DrawTextW(hdc,Butt_1.Text.Data.c_str(),-1,&Butt_1.Rect,Butt_1.Text.Pos_Horizontal|Butt_1.Text.Pos_Vertical|DT_SINGLELINE);
    SetTextColor(hdc,oldColor);

}


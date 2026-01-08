#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd) : VirtualPage(hwnd)
{
}
void TCPPage::Button_Animation(HDC hdc)
{
    HFONT HoldFont;
    HPEN HoldPen;

    Buttons.push_back(Button(Main_Rect, Main_Rect.left, Main_Rect.top + 100, 200, 100));
    COLORREF Text_Color = RGB(50, 0, 0);
    Buttons[0].Text_Set(DT_CENTER, DT_VCENTER, L"Connect", Text_Color);
    FillRect(hdc, &Buttons[0].Rect, Buttons[0].Color);
    HoldFont = (HFONT)SelectObject(hdc, Buttons[0].Text.Text_Style);
    COLORREF oldColor = GetTextColor(hdc);
    SetTextColor(hdc, Buttons[0].Text.Text_Collor);
    DrawTextW(hdc, Buttons[0].Text.Data.c_str(), -1, &Buttons[0].Rect, Buttons[0].Text.Pos_Horizontal | Buttons[0].Text.Pos_Vertical | DT_SINGLELINE);
    SetTextColor(hdc, oldColor);
    SelectObject(hdc, HoldFont);
}

void TCPPage::Pages_Func(HWND hwnd, LPARAM lparam)
{
    bool InButt_1 = Buttons[0].Btn_Func(hwnd,lparam);
    if (InButt_1)
    {
        Buttons[0].Color_Set(0, 0, 150);
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
    }
    else if (!InButt_1)
    {
        Buttons[0].Color_Set(150, 0, 0);
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
    }
}
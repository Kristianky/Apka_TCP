#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd) : VirtualPage(hwnd)
{
}
void TCPPage::Button_Create(HDC hdc)
{
    HFONT HoldFont;
    HPEN HoldPen;
    Buttons.push_back(Button(Main_Rect, Main_Rect.left, Main_Rect.top + 100, 200, 100));
    Buttons[1].Color_Set(0, 0, 150);
    COLORREF Text_Color = RGB(50, 0, 0);
    Buttons[1].Text_Set(DT_CENTER, DT_VCENTER, L"Connect", Text_Color);
    FillRect(hdc, &Buttons[1].Rect, Buttons[1].Color);
    HoldFont = (HFONT)SelectObject(hdc, Buttons[1].Text.Text_Style);
    COLORREF oldColor = GetTextColor(hdc);
    SetTextColor(hdc, Buttons[1].Text.Text_Collor);
    DrawTextW(hdc, Buttons[1].Text.Data.c_str(), -1, &Buttons[1].Rect, Buttons[1].Text.Pos_Horizontal | Buttons[1].Text.Pos_Vertical | DT_SINGLELINE);
    SetTextColor(hdc, oldColor);
    SelectObject(hdc, HoldFont);
}

void TCPPage::Pages_Func(HWND hwnd, HDC hdc, LPARAM lparam, WPARAM wparam)
{
    if (Buttons[1].Btn_Func(hwnd, lparam))
    {
        Buttons[1].Color_Set(0, 0, 0);
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
    }
    else
    {
        Buttons[1].Color_Set(0, 0, 150);
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
    }
}
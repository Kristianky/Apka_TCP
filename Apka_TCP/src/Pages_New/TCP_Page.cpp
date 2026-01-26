#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd) : VirtualPage(hwnd)
{
    Buttons.push_back(Button(Main_Rect, Main_Rect.left, Main_Rect.top + 100, 100, 100)); // Vytvorenie Tlacidla ----------------connect button
    Buttons[0].Inside_Bool.push_back(false);                                             // Premenne vnutri tlacidla pre booly
    Buttons[0].Inside_Bool.push_back(false);
    Draw_Text = {Main_Rect.left + 10, Main_Rect.top + 20, Main_Rect.left + 100, Main_Rect.top + 40};
}
void TCPPage::Button_Animation(HDC hdc)
{
    HFONT HoldFont;
    HPEN HoldPen;
    COLORREF Text_Color = RGB(50, 0, 0);
    // Nastavenie farby stvorca a nasledne vytlacenie pre -------Connect Button
    Buttons[0].Text_Set(DT_CENTER, DT_VCENTER, L"Connect", Text_Color);
    FillRect(hdc, &Buttons[0].Rect, Buttons[0].Color);
    //
    // Nastavenie farby a stylu textu pre ---------Connect Button
    HoldFont = (HFONT)SelectObject(hdc, Buttons[0].Text.Text_Style);
    COLORREF oldColor = GetTextColor(hdc);
    SetTextColor(hdc, Buttons[0].Text.Text_Collor);
    DrawTextW(hdc, Buttons[0].Text.Data.c_str(), -1, &Buttons[0].Rect, Buttons[0].Text.Pos_Horizontal | Buttons[0].Text.Pos_Vertical | DT_SINGLELINE);
    SetTextColor(hdc, oldColor);
    SelectObject(hdc, HoldFont);
    //
    // Menenie farby podla stavu mysi ---------------COnnect BUtton
    if (Buttons[0].Inside_Bool[1])
    {
        COLORREF Draw_Text_Color = RGB(0, 0, 150);
        HoldFont = (HFONT)SelectObject(hdc, &Draw_Text_Color);
        SetTextColor(hdc, Draw_Text_Color);
        DrawTextW(hdc, L"Connected", -1, &Draw_Text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        SetTextColor(hdc, oldColor);
    }
    //--------------------------------------------------------------------------
}

void TCPPage::Buttons_Func(HWND hwnd, LPARAM lparam)
{
    Buttons[0].Btn_In(Main_Hwnd, lparam);
    if (Buttons[0].InButt_1)
    {
        if (!Mouse::Lh_Butt_Down_Status)
        {
            Buttons[0].Color_Set(150, 0, 0);
        }
        else if (Mouse::Lh_Butt_Clicked_Status)
        {
            Buttons[0].Inside_Bool[1] = !Buttons[0].Inside_Bool[1];
            InvalidateRect(hwnd,&Draw_Text,false);
            if (Buttons[0].Inside_Bool[1])
            {
                Page_Calls();
            }
        }
        else if (Mouse::Lh_Butt_Down_Status)
        {
            Buttons[0].Color_Set(0, 150, 0);
        }
    }

    else
    {
        Buttons[0].Color_Set(0, 0, 150);
    }
}

void TCPPage::Buttons_Mouse_Clicked_Call(HWND Main_hwnd, UINT umsg, LPARAM lparam)
{
}

void TCPPage::Page_Calls()
{

    Client1.Connect();
    Client1.Send(L"Hallo");
    Client1.Disconect();
};
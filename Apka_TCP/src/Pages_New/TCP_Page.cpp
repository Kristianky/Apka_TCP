#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd) : VirtualPage(hwnd)
{
    Buttons.push_back(Button(Main_Rect, Main_Rect.left, Main_Rect.top + 100, 200, 100));    //Vytvorenie Tlacidla ----------------connect button
    Buttons[0].Inside_Bool.push_back(false);   //Premenne vnutri tlacidla pre booly
    Buttons[0].Inside_Bool.push_back(false);
}
void TCPPage::Button_Animation(HDC hdc)
{
    HFONT HoldFont;
    HPEN HoldPen;
    COLORREF Text_Color = RGB(50, 0, 0);
    //Nastavenie farby stvorca a nasledne vytlacenie pre -------Connect Button
    Buttons[0].Text_Set(DT_CENTER, DT_VCENTER, L"Connect", Text_Color);
    FillRect(hdc, &Buttons[0].Rect, Buttons[0].Color);
    //
    //Nastavenie farby a stylu textu pre ---------Connect Button
    HoldFont = (HFONT)SelectObject(hdc, Buttons[0].Text.Text_Style);
    COLORREF oldColor = GetTextColor(hdc);
    SetTextColor(hdc, Buttons[0].Text.Text_Collor);
    DrawTextW(hdc, Buttons[0].Text.Data.c_str(), -1, &Buttons[0].Rect, Buttons[0].Text.Pos_Horizontal | Buttons[0].Text.Pos_Vertical | DT_SINGLELINE);
    SetTextColor(hdc, oldColor);
    SelectObject(hdc, HoldFont);
    //
    //Menenie farby podla stavu mysi ---------------COnnect BUtton
    if (Buttons[0].Inside_Bool[0])
    {
        Buttons[0].Color_Set(150, 0, 0);
    }
    else
    {
        Buttons[0].Color_Set(0, 0, 150);
    }
    if(Buttons[0].Inside_Bool[1])
    {
        TextOutW(hdc,100,100,L";Connected",10);
    }
    //--------------------------------------------------------------------------
    
}

void TCPPage::Buttons_Func(HWND hwnd, LPARAM lparam)
{
    //Volanie pre Connect button ci je vnutry buttona ci nie
    bool InButt_1 = Buttons[0].Btn_In(hwnd, lparam);
    if (InButt_1 != Buttons[0].Inside_Bool[0])
    {
        Buttons[0].Inside_Bool[0] = InButt_1;
        InvalidateRect(hwnd, &Buttons[0].Rect, TRUE);
        UpdateWindow(hwnd);
    }
    else if (!InButt_1 && Buttons[0].Inside_Bool[0])
    {
        Buttons[0].Inside_Bool[0] = false;

        InvalidateRect(hwnd, &Buttons[0].Rect, TRUE);
        UpdateWindow(hwnd);
    }

    //Funkcia Connect buttona 
    if (InButt_1 && Buttons[0].L_Btn_Clicked)
    {
        Buttons[0].Inside_Bool[1] = !Buttons[0].Inside_Bool[1];
    }
    //------------------------------------------------------------
}

void TCPPage::Buttons_Mouse_Clicked_Call(HWND Main_hwnd,UINT umsg)
{
    Buttons[0].Btn_Clicked(Main_Hwnd,umsg);
}
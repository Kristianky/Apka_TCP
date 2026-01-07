#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd):VirtualPage(hwnd)
{}
void TCPPage::Button_Create(HDC hdc)
{
   
    Button Butt_1(Main_Rect,Main_Rect.left,Main_Rect.top + 100,200,100);
    Butt_1.Color_Set(0,0,150);
    Butt_1.Text_Set("CENTER","CENTER",L"Coneect");
    FillRect(hdc,&Butt_1.Rect,Butt_1.Color);
}


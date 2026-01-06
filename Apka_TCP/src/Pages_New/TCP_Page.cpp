#include "TCP_Page.h"
TCPPage::TCPPage(HWND hwnd):VirtualPage(hwnd)
{}
void TCPPage::Button(HDC hdc)
{
    HBRUSH Butt_Conect_Coll = CreateSolidBrush(RGB(0,0,60));
    RECT Butt_Connect = {Main_Rect.left,Main_Rect.top,Main_Rect.left + 500,Main_Rect.top + 500}; 
    FillRect(hdc,&Butt_Connect,Butt_Conect_Coll);
}
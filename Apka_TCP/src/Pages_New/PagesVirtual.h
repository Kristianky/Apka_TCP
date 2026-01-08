#ifndef _PAGESVIRTUAL_H_
#define _PAGESVIRTUAL_H_

#include <windows.h>
#include <string>
#include <vector>
#include "TCP_Client.h"
#include "Button.h"


class VirtualPage 
{
    protected:
    HWND Main_Hwnd;
    RECT Main_Rect;
    public:
    VirtualPage () = default;
    virtual ~VirtualPage() {};
    VirtualPage (HWND hwnd):Main_Hwnd{hwnd}{GetClientRect(hwnd,&Main_Rect);Main_Rect.top = Main_Rect .top + 30;}
    virtual void Button_Create(HDC hdc) = 0;
    virtual void Pages_Func(HWND hwnd,HDC hdc,LPARAM lparam,WPARAM wparam) = 0;

};

#endif
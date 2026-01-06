#ifndef _PAGESVIRTUAL_H_
#define _PAGESVIRTUAL_H_

#include <windows.h>
#include <string>
#include <vector>
#include "TCP_Client.h"

class VirtualPage 
{
    protected:
    HWND Main_Hwnd;
    RECT Main_Rect;

    public:
    VirtualPage () = default;
    virtual ~VirtualPage() {};
    VirtualPage (HWND hwnd):Main_Hwnd{hwnd}{GetClientRect(hwnd,&Main_Rect);Main_Rect.top = Main_Rect .top + 30;}
    virtual void Button(HDC hdc) = 0;

};

#endif
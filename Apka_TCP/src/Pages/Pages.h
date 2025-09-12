
#ifndef _PAGES_H_
#define _PAGES_H_

#include <windows.h>
class Pages 
{
protected:
   HWND *Windows;
   int *Number_Of_Windows;
   wchar_t **Windows_CLASS;
   wchar_t **Windows_Names;
   int *Windows_PositionsX;
   int *Windows_PositionsY;
   wchar_t *Page_Name;

public:
   Pages();
   virtual ~Pages();
   virtual void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) = 0;
   virtual void Destroy_WindowW(HWND *Buttons) = 0;
   virtual void Buttons_Function(LPARAM lparam,WPARAM wparamonst,int &page_num,HWND *Buttons) = 0;
};

#endif
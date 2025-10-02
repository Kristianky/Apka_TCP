
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
   HWND Main_hwnd;
   HDC Main_hdc;
   

public:
   Pages() = default;
   Pages(HWND hwnd,HDC hdc);
   virtual ~Pages();
   virtual void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) = 0;
   virtual void Destroy_WindowW(HWND *Buttons);
   virtual void Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,bool *Buttons_state) = 0;
   virtual void Cout_Button_1() = 0;
   virtual void Cout_Create() = 0;
   virtual HWND Get_hwnd() = 0;
   virtual HDC Get_hdc() = 0;
};

#endif
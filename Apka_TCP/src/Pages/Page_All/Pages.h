
#ifndef _PAGES_H_
#define _PAGES_H_

#include "Sparse_Matrix.h"
#include <windows.h>
#include <string>
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
   wchar_t **Buffer_1;
   std::wstring *Buffer_2;
   Sparse_Matrix Sparse_Matrix;
   int *Size_Of_Buffers;
   int *Indexes;

public:
   Pages() = default;
   Pages(HWND hwnd);
   virtual ~Pages();
   virtual void Create_WindowW(HWND *Buttons,int BUTTON) = 0;
   virtual void Destroy_WindowW(HWND *Buttons);
   virtual void Buttons_Function(int &page_num,HWND *Buttons,bool *Buttons_state,WPARAM wparam,LPARAM lparam) = 0;
   virtual void Cout_Button_1(HDC hdc) = 0;
   virtual void Cout_Create(HDC hdc) = 0;
   virtual HWND Get_hwnd() = 0;
   virtual void Key_Board_Func(WPARAM wparam,LPARAM lparam,int ID_Button,HWND *Window) = 0;
 
};

#endif
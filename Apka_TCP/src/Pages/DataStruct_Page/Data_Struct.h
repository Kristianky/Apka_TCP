#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "Pages.h"

class Data_Struct_Page:public Pages{
     public:
         Data_Struct_Page();
         void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) override;
         virtual ~Data_Struct_Page();
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,HWND Main_hwnd,bool &Buttons_State[]) override;   
         virtual void Cout(HDC hdc) override;
};

#endif
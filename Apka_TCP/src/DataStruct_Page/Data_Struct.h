#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "Pages.h"

class Data_Struct_Page:public Pages{
     public:
         Data_Struct_Page();
         virtual ~Data_Struct_Page();
         virtual void Create_WindowW (HWND *Buttons,HWND Main_Hwnd,int BUTTON) override;
         virtual void Destroy_WindowW(HWND *Buttons) override;
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,HWND Main_hwnd) override;   
         virtual void Cout(HWND hwnd) override;
};

#endif
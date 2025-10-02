#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "Pages.h"


class Data_Struct_Page:public Pages{
     public:
         Data_Struct_Page(HWND hwnd,HDC hdc);
         void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) override;
         virtual ~Data_Struct_Page();
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,bool *Buttons_state) override;   
         virtual void Cout_Button_1() override;
         virtual void Cout_Create() override;
};

#endif
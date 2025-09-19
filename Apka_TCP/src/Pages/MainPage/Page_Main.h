#ifndef _PAGE_MAIN_H_
#define _PAGE_MAIN_H_

#include "Pages.h"
#include "Data_Struct.h"
class Main_Page:public Pages{
      private:
          Data_Struct_Page *Data_Struct;
      public:
         Main_Page();
         virtual ~Main_Page();
         virtual void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) override;
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparamonst,int &page_num,HWND *Buttons,HWND Main_hwnd,bool &Buttons_State[]) override;
         virtual void Cout(HDC hdc) override;
};

#endif
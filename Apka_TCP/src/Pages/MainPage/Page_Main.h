#ifndef _PAGE_MAIN_H_
#define _PAGE_MAIN_H_

#include "Pages.h"
#include "Data_Struct.h"
class Main_Page:public Pages{
      private:
          Data_Struct_Page *Data_Struct;
      public:
         Main_Page(HWND hwnd,HDC hdc);
         virtual ~Main_Page();
         virtual void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) override;
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparamonst,int &page_num,HWND *Buttons,bool *Buttons_state) override;
         virtual void Cout_Button_1() override;
         virtual void Cout_Create() override;
         virtual HWND Get_hwnd() {return Main_hwnd;}
         virtual HDC Get_hdc() {return Main_hdc;}
};

#endif
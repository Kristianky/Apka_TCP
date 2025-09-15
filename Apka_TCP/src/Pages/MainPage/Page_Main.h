#ifndef _PAGE_MAIN_H_
#define _PAGE_MAIN_H_

#include "Pages.h"

class Main_Page:public Pages{
      public:
         Main_Page();
         virtual ~Main_Page();
         
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparamonst,int &page_num,HWND *Buttons,HWND Main_hwnd) override;
         virtual void Cout(HWND hwnd) override;
};

#endif
#ifndef _PAGE_MAIN_H_
#define _PAGE_MAIN_H_

#include "Pages.h"

class Main_Page:public Pages{
      public:
         Main_Page();
         virtual ~Main_Page();
         virtual void Create_WindowW (HWND hwnd,int BUTTON) override;
         virtual void Destroy_WindowW(HWND hwnd) override;
};

#endif
#ifndef _PAGE_MAIN_H_
#define _PAGE_MAIN_H_

#include "Pages.h"

class Main_Page:Pages{
      public:
         Main_Page();
         virtual ~Main_Page();
         virtual void Create_Window(HWND hwnd) override;
};

#endif
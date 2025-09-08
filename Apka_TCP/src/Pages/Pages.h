
#ifndef _PAGES_H_
#define _PAGES_H_

#include "Moja_Apka.h"
class Pages 
{
private:
   HWND *Buttons;
   wchar_t *Buttons_Names;
   int *Buttons_PositionsX;
   int *Buttons_PositionsY;

public:
   Pages();
   virtual ~Pages();
   virtual void Create_Window();
};

#endif
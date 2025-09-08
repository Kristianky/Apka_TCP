
#ifndef _PAGES_H_
#define _PAGES_H_

#include "Moja_Apka.h"
class Pages 
{
private:
   HWND *Windows;
   int Number_Of_Windows;
   wchar_t **Windows_CLASS;
   wchar_t **Windows_Names;
   int *Windows_PositionsX;
   int *Windows_PositionsY;
   wchar_t *Page_Name;

public:
   Pages();
   virtual ~Pages();
   virtual void Create_Window(HWND hwnd);
};

#endif
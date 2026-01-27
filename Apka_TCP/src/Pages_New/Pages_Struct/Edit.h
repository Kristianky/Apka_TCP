#ifndef _EDIT_H_
#define _EDIT_H_

#include <windows.h>
#include <string>
#include <vector>
#include "Mouse.h"

class EditWindow
{
protected:
    int Sur_X; //Suradnice tlacidla
    int Sur_Y; 
    int Edt_Width, Edt_Lenght; //Velkost tlacidla
public:
    RECT Rect;
    void Color_Set(int Red, int Green, int Blue);
    void Edt_In(HWND Main_hwnd, LPARAM lparam);
    HBRUSH Color;
    EditWindow(RECT &Main_Rect, int X, int Y, int Width, int Lenght); 
    bool InButt;
};

#endif
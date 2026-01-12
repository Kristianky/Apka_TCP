#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <windows.h>
#include <string>
#include <vector>

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#endif

/** @brief Data = Text, */
struct Button_Text
{
    std::wstring Data;  
    int Pos_Vertical, Pos_Horizontal;
    COLORREF Text_Collor;
    HFONT Text_Style;
};
class Button
{
protected:
    int Sur_X; //Suradnice tlacidla
    int Sur_Y; 
    int Btn_Width, Btn_Lenght; //Velkost tlacidla

public:
    bool InButt_1;
    bool Btn_Clicked;  //Stav Laveho tlacidla mysi
    std::vector<bool> Inside_Bool; //Interne stavy volne vyuzitie 0 je pre mys ci je vnutri 1 je pre funkciu tlacidla
    RECT Rect;  //Stvorec pre vytvorenie tlacidla
    HBRUSH Color;  //farba tlacidla
    Button_Text Text;   //Struktura pre nastavenie textu v tlacidle
    Button(RECT &Main_Rect, int X, int Y, int Width, int Lenght); 
    void Color_Set(int Red, int Green, int Blue);  //nastavenie farby tlacidla
    void Text_Set(int Position_1, int Position_2, std::wstring Text_In, const COLORREF &Color_Temp);  //Nastavenie textu tlacidla
    void Btn_In(HWND Main_hwnd, LPARAM lparam); //Sledovanie mysi na hlokne
    bool L_Btn_Down(HWND Main_hwnd, UINT umsg,LPARAM lparam); //Sledovanie tlacidiel mysi
    bool L_Btn_Up(HWND Main_hwnd, UINT umsg,LPARAM lparam);
};

#endif
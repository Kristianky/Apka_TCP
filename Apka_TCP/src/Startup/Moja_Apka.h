#ifndef _MOJA_APKA_H_
#define _MOJA_APKA_H_

#ifndef GET_X_LPARAM
  #define GET_X_LPARAM(lp) ( (int)(short)LOWORD(lp) )
  #define GET_Y_LPARAM(lp) ( (int)(short)HIWORD(lp) )
#endif

#include <windows.h>
#include "Pages.h"
#include "Page_Main.h"  
#include "PagesVirtual.h"
#include "TCP_Page.h"

#define ID_BUTTONS 10000
#define ID_EDIT 20000
class Moja_Apka
{
private:
    int Page_Num;
    HWND hwnd{};
    HWND *Edit_Boxes;
    HWND *Button;
    bool *Buttons_State;
   
    // statické setup/redirect
    static LRESULT CALLBACK WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
     Pages *Page = nullptr;
    VirtualPage *New_Page = nullptr;
    // tvoja "pravá" WndProc ako členská metóda
    LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
    // hwnd->okno ktoremu je sprava urcena...
   
    // uint -> premmene napr z klavesnice mysi atd..
    // wparam-> stavovy parameter doplnujuce info
    // lparam -> dalsie parametre napr poloha kurzora atd

public:
    Moja_Apka(HINSTANCE Hinstance);
    ~Moja_Apka();
    void Page_Render();
    HWND Get_HWND() { return hwnd; }
    void Render_Page(int &Num_Page,LPARAM lparam,WPARAM wparam);
    void Welcome_Page(WPARAM wparam,LPARAM lparam);
    void Paint(HDC hdc);
    void Render_Page_Keyboard(WPARAM wpram,LPARAM lparam);
    void Border(HDC hdc,RECT Main_Rect);
    bool Border_Buttons_Draw(HWND hwnd,LPARAM lparam);
    void Draw_Buttons_Border(HWND hwnd,LPARAM lparam,HDC hdc);
    void Mouse_Cursor_Move(HWND hwnd,LPARAM lparam);
    void L_BTN_Click(HWND hwnd);
    };
  

#endif
#ifndef _MOJA_APKA_H_
#define _MOJA_APKA_H_


#include <windows.h>
#include "Pages.h"
#include "Page_Main.h"  


#define ID_BUTTONS 10000
class Moja_Apka
{
private:
    int Page_Num;
    HWND hwnd{};
    HWND *Button;
    bool *Buttons_State;
   
    // statické setup/redirect
    static LRESULT CALLBACK WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
     Pages *Page = nullptr;
    // tvoja "pravá" WndProc ako členská metóda
    LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
    // hwnd->okno ktoremu je sprava urcena...
    wchar_t *Buffer;
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
    };

#endif
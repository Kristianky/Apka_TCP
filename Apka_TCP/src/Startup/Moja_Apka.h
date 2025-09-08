#ifndef _MOJA_APKA_H_
#define _MOJA_APKA_H_

#include <windows.h>

#define ID_BUTTONS 1
class Moja_Apka
{
private:
    int Page_Num;
    HWND hwnd{};
    HWND Button;
    // statické setup/redirect
    static LRESULT CALLBACK WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
    void Render_Page(int Button);
};

#endif
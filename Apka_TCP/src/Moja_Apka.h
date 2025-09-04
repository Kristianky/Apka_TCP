#ifndef _MOJA_APKA_H_
#define _MOJA_APKA_H_

#include <windows.h>

#define ID_BUTTONS 1
class Moja_Apka{
    private:
wchar_t Buffer_For_Text[300];
int Page_Num;
static HWND TEXTS[10];
static HWND Buttons[20];
const static int Number_Of_Buttons{5};
const wchar_t **Buttons_Funcionallity;
const wchar_t **Buttons_Names;
int *Button_X;
int *Button_Y;
   HWND hwnd{};

    // statické setup/redirect
    static LRESULT CALLBACK WndProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WndProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    // tvoja "pravá" WndProc ako členská metóda
    LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
// hwnd->okno ktoremu je sprava urcena...

// uint -> premmene napr z klavesnice mysi atd..
// wparam-> stavovy parameter doplnujuce info
// lparam -> dalsie parametre napr poloha kurzora atd

public:
Moja_Apka(HINSTANCE Hinstance);
~Moja_Apka ();
void Page_Render();
HWND Get_HWND(){return hwnd;}
};

#endif
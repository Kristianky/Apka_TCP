#ifndef _MOJA_APKA_H_
#define _MOJA_APKA_H_

#include <windows.h>

#define ID_BUTTONS 1
class Moja_Apka{
    private:
<<<<<<< HEAD:Apka_TCP/src/Startup/Moja_Apka.h
int Page_Num;
=======
wchar_t *Buffer_For_Text;
int Page_Num;
HWND *TEXTS;
HWND *Buttons;
const static int Number_Of_Buttons{5};
const wchar_t **Buttons_Funcionallity;
const wchar_t **Buttons_Names;
int *Button_X;
int *Button_Y;
>>>>>>> c9ef392a1a47a15076a7992e506eb650ac2431da:Apka_TCP/src/Moja_Apka.h
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
~Moja_Apka ();
void Page_Render();
HWND Get_HWND(){return hwnd;} 
};

#endif
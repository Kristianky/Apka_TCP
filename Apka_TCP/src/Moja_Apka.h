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
// hwnd->okno ktoremu je sprava urcena...

// uint -> premmene napr z klavesnice mysi atd..
// wparam-> stavovy parameter doplnujuce info
// lparam -> dalsie parametre napr poloha kurzora atd
LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
    switch (umsg)
    {
        // vytvori okna tlacidlo 1,2 a edit okienko
    case WM_CREATE:
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...
        Buttons[0] = CreateWindow(L"BUTTON",L"Vitajte pre pokracovanie klikni",WS_CHILD|WS_VISIBLE,600,250,400,200,hwnd,(HMENU)(ID_BUTTONS),NULL,NULL);
        break;
    case WM_COMMAND:
        switch (LOWORD(wparam)) // toto urcuje ktore tlacidlo bolo stlacene alebo ine stavy
        {
        case (ID_BUTTONS):
              DestroyWindow(Buttons[0]);
              Page_Num=1;
              break;
        case (ID_BUTTONS + 1):            //tlacidlo zobraz text
        {
            HWND h_Edit = GetDlgItem(hwnd, (ID_BUTTONS+2)); // urci co sa stane po stlaceni tlacidla 1 v tomto pripade precita text z edit a zapise ho do buffera
            GetWindowTextW(h_Edit, Buffer_For_Text, 300);
            wchar_t buffer_for_num[1];
            wsprintfW(buffer_for_num,L"%d",Page_Num);
            MessageBoxW(hwnd, Buffer_For_Text, L"Sprava", MB_OK | MB_ICONINFORMATION);
            MessageBoxW(hwnd,buffer_for_num, L"Sprava", MB_OK | MB_ICONINFORMATION);
            break;
        }
        //Priratoavanie a odratavanie stran
        case (ID_BUTTONS + 5):          //tlacidlo exit
            PostQuitMessage(0);
            break;
        case (ID_BUTTONS + 4):       //tlacidlo next slide
            Page_Num++;
            if (Page_Num > 5)
            {
                Page_Num = 0;
            }
            break;
        case (ID_BUTTONS + 3):   //tlacidlo prev slide
            Page_Num--;
            if (Page_Num < 0)
            {
                Page_Num = 5;
            }
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0); // zavrie appku
        break;
    default:
        return DefWindowProc(hwnd, umsg, wparam, lparam);
        break;
    }
    //prepinanie stran a nastavovanie tlacitok
        
    return 0;
}
public:
Moja_Apka(HINSTANCE Hinstance);
~Moja_Apka ();
void Page_Render();
};

#endif
#include "Moja_Apka.h"

Moja_Apka::Moja_Apka(HINSTANCE Hinstance)
{

    Page_Num = 0;
    Button = new HWND[10];
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna
    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = Moja_Apka::WindowProcSetup;   // ukaze na funkciu ktoru sme si hore zadefinovali
    wc.hInstance = Hinstance;                      // priraduje handle
    wc.lpszClassName = CLASSNAME;                  // priradi meno okna
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5); // nastavi styl a farbu okna
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // nacita kurzor a nastavi styl
    Buttons_State = new bool[5];
    Buttons_State[0] = false;
    RegisterClassW(&wc); // regitruje classu do windows az po tomto kroku mozme vytvorit okno

    hwnd = CreateWindowExW( // vytvorenie hl okna
        0,
        CLASSNAME,
        L"Moja Appka",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 250,
        NULL, NULL, Hinstance, this);
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
}
Moja_Apka::~Moja_Apka()
{
}
LRESULT Moja_Apka::WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
  
    switch (umsg)
    {
        // vytvori okna tlacidlo 1,2 a edit okienko
    case WM_CREATE:
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...

        Button[0] = CreateWindowW(L"BUTTON", L"Vitajte pre pokracovanie klikni", WS_CHILD | WS_VISIBLE, 600, 250, 400, 200, hwnd, (HMENU)(ID_BUTTONS), NULL, NULL);

        break;
    case WM_COMMAND:
    {
        Render_Page(Page_Num, lparam, wparam);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0); // zavrie appku
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT Ps;
        hdc = BeginPaint(hwnd, &Ps);

        Paint();
        EndPaint(hwnd, &Ps);
        break;
    }

    default:
        return DefWindowProc(hwnd, umsg, wparam, lparam);

        // prepinanie stran a nastavovanie tlacitok
    }
    return 0;
}
LRESULT CALLBACK Moja_Apka::WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_NCCREATE)
    {                                                                                   // NCCREATE ide este pre CREATE potrebujeme to kvoli this pointru este pred vytvorenim okna
        auto cs = reinterpret_cast<CREATESTRUCT *>(lParam);                             // CREATESTRUCT je funkcia ktora vynika pri vytvarani okna
                                                                                        // cize vtedy potrebujeme z nej dostat pointer aby sme mohli manipulovat s oknom
        auto self = reinterpret_cast<Moja_Apka *>(cs->lpCreateParams);                  // toto ulozi pointer z create struct do nasej appky
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)self);                          // toto ulozi pointer do pamate ktoru ma windows urcenu pre uzivatelov pri vytvarani okien
        SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)&Moja_Apka::WindowProcRedirect); // tu ulozime pointer do urcenej pamate windowsom                                                                  //mozme ptr prepisovat a ukladat ale tato pamat je presne urcena wndproc funkciu
        return self->WindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK Moja_Apka::WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    auto self = reinterpret_cast<Moja_Apka *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    return self->WindowProc(hwnd, msg, wParam, lParam);
}

void Moja_Apka::Render_Page(int &Page_Num, LPARAM lparam, WPARAM wparam)
{
    switch (Page_Num)
    {
    case 0:
        Welcome_Page(wparam);
        break;
    case 1:
        if (!Page)
        {
            Page = new Main_Page(hwnd,hdc);
        }
        Page->Buttons_Function(lparam, wparam, Page_Num, Button, Buttons_State);
        break;
    case 2:
        Page = nullptr;
        Page = new Data_Struct_Page(hwnd,hdc);
        Page->Buttons_Function(lparam, wparam,  Page_Num, Button,  Buttons_State);
        break;
    }
}

void Moja_Apka::Welcome_Page(WPARAM wparam)
{
    switch (LOWORD(wparam))
    {
    case (ID_BUTTONS):
        DestroyWindow(Button[0]);
        Page = new Main_Page(hwnd,hdc);
        Page->Create_WindowW(Button, hwnd, ID_BUTTONS);
        Page_Num = 1;
    }
}

void Moja_Apka::Paint()
{
    if (Buttons_State[0])
    {
        if (!Page)
        {
            Page = new Data_Struct_Page(hwnd,hdc);
        }
        Page->Cout_Button_1();
    }
    else if(!Buttons_State[0]){
         RECT rect = {200, 200, 200, 200};
         FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW+5));
    }
  
    if (Page_Num == 2){
        if(!Page){
            Page = new Data_Struct_Page(hwnd,hdc);
        }
        Page->Cout_Create();
    }
}

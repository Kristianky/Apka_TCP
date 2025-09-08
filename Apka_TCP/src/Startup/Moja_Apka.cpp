#include "Moja_Apka.h"

Moja_Apka::Moja_Apka(HINSTANCE Hinstance){

    Page_Num = 0;
    
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna

    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = Moja_Apka::WindowProcSetup;                   // ukaze na funkciu ktoru sme si hore zadefinovali
    wc.hInstance = Hinstance;                      // priraduje handle
    wc.lpszClassName = CLASSNAME;                  // priradi meno okna
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5); // nastavi styl a farbu okna
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // nacita kurzor a nastavi styl

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
Moja_Apka::~Moja_Apka(){
  
}
LRESULT Moja_Apka::WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam) 
{
    switch (umsg)
    {
        // vytvori okna tlacidlo 1,2 a edit okienko
    case WM_CREATE:
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...
       
        Button = CreateWindowW(L"BUTTON",L"Vitajte pre pokracovanie klikni",WS_CHILD|WS_VISIBLE,600,250,400,200,hwnd,(HMENU)(ID_BUTTONS),NULL,NULL);

        break;
    case WM_COMMAND:
        switch (LOWORD(wparam)) // toto urcuje ktore tlacidlo bolo stlacene alebo ine stavy
        {
        case (ID_BUTTONS):
              if (Page_Num == 0){
              DestroyWindow(Button);
              Page_Num=1;
              break;}
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
}
LRESULT CALLBACK Moja_Apka::WindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_NCCREATE) {                                           //NCCREATE ide este pre CREATE potrebujeme to kvoli this pointru este pred vytvorenim okna
        auto cs = reinterpret_cast<CREATESTRUCT*>(lParam);          //CREATESTRUCT je funkcia ktora vynika pri vytvarani okna 
                                                                    //cize vtedy potrebujeme z nej dostat pointer aby sme mohli manipulovat s oknom
        auto self = reinterpret_cast<Moja_Apka*>(cs->lpCreateParams);    //toto ulozi pointer z create struct do nasej appky
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)self);   //toto ulozi pointer do pamate ktoru ma windows urcenu pre uzivatelov pri vytvarani okien 
        SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)&Moja_Apka::WindowProcRedirect);  //tu ulozime pointer do urcenej pamate windowsom                                                                  //mozme ptr prepisovat a ukladat ale tato pamat je presne urcena wndproc funkciu 
        return self->WindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK Moja_Apka::WindowProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    auto self = reinterpret_cast<Moja_Apka*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    return self->WindowProc(hwnd, msg, wParam, lParam);
}

void Moja_Apka::Render_Page(int Button){

}
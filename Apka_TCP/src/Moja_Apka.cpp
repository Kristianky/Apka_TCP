#include "Moja_Apka.h"
Moja_Apka::Moja_Apka(HINSTANCE Hinstance){
    Button_X = new int [] {0,600,0,0,1300};
    Button_Y = new int [] {10,10,210,410,700};
    const wchar_t *Buttons_Func [] {{L"BUTTON"},{L"EDIT"}};
    const wchar_t *Buttons_N []  {{L"Zobraz Text"},{L"Vloz Text"},{L"Previous slide"},{L"Next slide"},{L"Exit"}};
    Buttons_Funcionallity = Buttons_Func;
    Buttons_Names = Buttons_N;
    Page_Num = 0;
    delete [] Buttons_Func;
    delete [] Buttons_N;
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna

    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = Moja_Apka::WindowProc;                   // ukaze na funkciu ktoru sme si hore zadefinovali
    wc.hInstance = Hinstance;                      // priraduje handle
    wc.lpszClassName = CLASSNAME;                  // priradi meno okna
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5); // nastavi styl a farbu okna
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // nacita kurzor a nastavi styl

    RegisterClassW(&wc); // regitruje classu do windows az po tomto kroku mozme vytvorit okno

    HWND hwnd = CreateWindowExW( // vytvorenie hl okna
        0,
        CLASSNAME,
        L"Moja Appka",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 250,
        NULL, NULL, Hinstance, NULL);

}
Moja_Apka::~Moja_Apka(){
    delete[] Buttons_Funcionallity;
    delete[] Buttons_Names;
    delete[] Button_X;
    delete[] Button_Y;
}
void Moja_Apka::Page_Render(){
     
}
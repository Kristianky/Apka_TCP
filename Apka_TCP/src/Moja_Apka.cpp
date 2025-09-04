#include "Moja_Apka.h"
Moja_Apka::Moja_Apka(HINSTANCE Hinstance){
    Button_X = new int [] {0,600,0,0,1300};
    Button_Y = new int [] {10,10,210,410,700};
    const wchar_t *Buttons_Func [] {{L"BUTTON"},{L"EDIT"}};
    const wchar_t *Buttons_N []  {{L"Zobraz Text"},{L"Vloz Text"},{L"Previous slide"},{L"Next slide"},{L"Exit"}};
    Buttons_Funcionallity = Buttons_Func;
    Buttons_Names = Buttons_N;
    Page_Num = 0;
    Buttons = new HWND[20];
    TEXTS = new HWND[20];
   
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna

    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = Moja_Apka::WndProcSetup;                   // ukaze na funkciu ktoru sme si hore zadefinovali
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
LRESULT Moja_Apka::WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
    switch (umsg)
    {
        // vytvori okna tlacidlo 1,2 a edit okienko
    case WM_CREATE:
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...
        Buttons[0] = CreateWindowW(L"BUTTON",L"Vitajte pre pokracovanie klikni",WS_CHILD|WS_VISIBLE,600,250,400,200,hwnd,(HMENU)(ID_BUTTONS),NULL,NULL);
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
void Moja_Apka::Page_Render(){
     
}
LRESULT CALLBACK Moja_Apka::WndProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_NCCREATE) {                                           //NCCREATE ide este pre CREATE potrebujeme to kvoli this pointru este pred vytvorenim okna
        auto cs = reinterpret_cast<CREATESTRUCT*>(lParam);          //CREATESTRUCT je funkcia ktora vynika pri vytvarani okna 
                                                                    //cize vtedy potrebujeme z nej dostat pointer aby sme mohli manipulovat s oknom
        auto self = reinterpret_cast<Moja_Apka*>(cs->lpCreateParams);    //toto ulozi pointer z create struct do nasej appky
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)self);   //toto ulozi pointer do pamate ktoru ma windows urcenu pre uzivatelov pri vytvarani okien 
        SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)&Moja_Apka::WndProcRedirect);  //tu ulozime pointer do urcenej pamate windowsom
                                                                                      //mozme ptr prepisovat a ukladat ale tato pamat je presne urcena wndproc funkciu 
        return self->WindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK Moja_Apka::WndProcRedirect(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    auto self = reinterpret_cast<Moja_Apka*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    return self->WindowProc(hwnd, msg, wParam, lParam);
}

#include <windows.h>

#define ID_BUTTONS 1

wchar_t Buffer_For_Text[300];
// hwnd->okno ktoremu je sprava urcena...

// uint -> premmene napr z klavesnice mysi atd..
// wparam-> stavovy parameter doplnujuce info
// lparam -> dalsie parametre napr poloha kurzora atd
LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
    static signed int Page_Num{};
    static HWND Buttons[20];
    static HWND TEXTS[10];
    static int Number_Of_Buttons{20};
    static const wchar_t *Buttons_Funcionallity []{{L"BUTTON"},{L"EDIT"}};
    static const wchar_t *Buttons_Names [] {{L"Zobraz Text"},{L"Vloz Text"},{L"Previous slide"},{L"Next slide"},{L"Exit"}};
    static int Button_X[]{0,600,0,0,1300};
    static int Butoon_Y[]{10,10,210,410,700};
    switch (umsg)
    {
        // vytvori okna tlacidlo 1,2 a edit okienko
    case WM_CREATE:
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...
        for(int i{};i < 5;i++){
            int j{};
               if(i == 0){j = 0;}
               else if(i == 1){j = 1;}
               else if(i == 2){j = 0;}
               else if(i == 3){j = 0;}
               else if(i == 4){j = 0;}
        CreateWindow(Buttons_Funcionallity[j], Buttons_Names [i],  WS_CHILD|WS_VISIBLE, Button_X[i], Butoon_Y[i], 150, 100, hwnd, (HMENU)(ID_BUTTONS+i), NULL, NULL);
        }
        break;
    case WM_COMMAND:
        switch (LOWORD(wparam)) // toto urcuje ktore tlacidlo bolo stlacene alebo ine stavy
        {
        case (ID_BUTTONS + 0):            //tlacidlo zobraz text
        {
            HWND h_Edit = GetDlgItem(hwnd, (ID_BUTTONS+1)); // urci co sa stane po stlaceni tlacidla 1 v tomto pripade precita text z edit a zapise ho do buffera
            GetWindowTextW(h_Edit, Buffer_For_Text, 300);
            wchar_t buffer_for_num[1];
            wsprintfW(buffer_for_num,L"%d",Page_Num);
            MessageBoxW(hwnd, Buffer_For_Text, L"Sprava", MB_OK | MB_ICONINFORMATION);
            MessageBoxW(hwnd,buffer_for_num, L"Sprava", MB_OK | MB_ICONINFORMATION);
            break;
        }
        //Priratoavanie a odratavanie stran
        case (ID_BUTTONS + 4):          //tlacidlo exit
            PostQuitMessage(0);
            break;
        case (ID_BUTTONS + 3):       //tlacidlo next slide
            Page_Num++;
            if (Page_Num > 5)
            {
                Page_Num = 0;
            }
            break;
        case (ID_BUTTONS + 2):   //tlacidlo prev slide
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
      switch (Page_Num)
        {
        case 0:
            ShowWindow(Buttons[0],SW_SHOW);
            break;
        case 1:
            ShowWindow(Buttons[0],SW_HIDE);
            break;
        default:
            break;
        }
    return 0;
}

// histance je unikatne cislo okna
// Histance hprevinstance je pre zastarale systemy moze byt null
// lpwstr-> retazec priradeny pri vytvarani
// ncmdshow-> ako sa ma hl okno zobrazovat
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{                                                  // main funkcia
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna

    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = WindowProc;                   // ukaze na funkciu ktoru sme si hore zadefinovali
    wc.hInstance = hInstance;                      // priraduje handle
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
        NULL, NULL, hInstance, NULL);

    if (!hwnd)
        return 0; // kontrola handlu

    ShowWindow(hwnd, nCmdShow); // toto musi byt aby sa okno zobrazilo
    UpdateWindow(hwnd);         // Po tomto mozme prekreslovat atd

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    { // Caka na podnety z von ak sa bude rovnat nule appka sa vypne
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

//pc home

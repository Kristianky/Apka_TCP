#include <windows.h>

#define ID_BUTTON_SHOW_TEXT 1
#define ID_BUTTON_END 2
#define ID_EDIT 3
#define NEXT_SLIDE_BUTTON 4
#define PREV_SLIDE_BUTTON 5

wchar_t Buffer_For_Text[300];
// hwnd->okno ktoremu je sprava urcena...
// uint -> premmene napr z klavesnice mysi atd..
// wparam-> stavovy parameter doplnujuce info
// lparam -> dalsie parametre napr poloha kurzora atd
LRESULT CALLBACK WindowProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
    static signed int Page_Num{};
    switch (umsg)
    {
        // vytvori okna tlacidlo 1,2 a edit okienko
    case WM_CREATE:
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...
        CreateWindowW(L"BUTTON", L"Zobraz text", WS_VISIBLE | WS_CHILD, 500, 10, 150, 100, hwnd, (HMENU)ID_BUTTON_SHOW_TEXT, NULL, NULL);
        CreateWindowW(L"BUTTON", L"Koniec", WS_VISIBLE | WS_CHILD, 1000, 10, 150, 100, hwnd, (HMENU)ID_BUTTON_END, NULL, NULL);
        CreateWindowW(L"EDIT", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT, 10, 10, 150, 100, hwnd, (HMENU)ID_EDIT, NULL, NULL);
        CreateWindowW(L"BUTTON", L"NEXT SLIDE", WS_VISIBLE | WS_CHILD, 10, 300, 150, 100, hwnd, (HMENU)NEXT_SLIDE_BUTTON, NULL, NULL);
        CreateWindowW(L"BUTTON", L"PREV SLIDE", WS_VISIBLE | WS_CHILD, 10, 450, 150, 100, hwnd, (HMENU)PREV_SLIDE_BUTTON, NULL, NULL);
        break;
    case WM_COMMAND:
        switch (LOWORD(wparam)) // toto urcuje ktore tlacidlo bolo stlacene alebo ine stavy
        {
        case ID_BUTTON_SHOW_TEXT:
        {
            HWND h_Edit = GetDlgItem(hwnd, ID_EDIT); // urci co sa stane po stlaceni tlacidla 1 v tomto pripade precita text z edit a zapise ho do buffera
            GetWindowTextW(h_Edit, Buffer_For_Text, 300);
            wchar_t buffer_for_num[1];
            wsprintfW(buffer_for_num,L"%d",Page_Num);
            MessageBoxW(hwnd, Buffer_For_Text, L"Sprava", MB_OK | MB_ICONINFORMATION);
            MessageBoxW(hwnd,buffer_for_num, L"Sprava", MB_OK | MB_ICONINFORMATION);
            break;
        }

        case ID_BUTTON_END:
            PostQuitMessage(0);
            break;
        case NEXT_SLIDE_BUTTON:
            Page_Num++;
            if (Page_Num > 5)
            {
                Page_Num = 0;
            }
            break;
        case PREV_SLIDE_BUTTON:
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

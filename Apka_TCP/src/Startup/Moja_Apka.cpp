#include "Moja_Apka.h"

Moja_Apka::Moja_Apka(HINSTANCE Hinstance)
{

    Page_Num = 0;
    Button = new HWND[17];
    const wchar_t CLASSNAME[] = L"MojeOknoTrieda"; // Tu si mozme nastavit hlavicku okna
    WNDCLASSW wc{};                                // vytvorenie classy appky
    wc.lpfnWndProc = Moja_Apka::WindowProcSetup;   // ukaze na funkciu ktoru sme si hore zadefinovali
    wc.hInstance = Hinstance;                      // priraduje handle
    wc.lpszClassName = CLASSNAME;                  // priradi meno okna
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5); // nastavi styl a farbu okna
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // nacita kurzor a nastavi styl
    Buttons_State = new bool[5];
    for (int i{}; i < 4; i++)
    {
        Buttons_State[i] = false;
    }
    RegisterClassW(&wc); // regitruje classu do windows az po tomto kroku mozme vytvorit okno

    hwnd = CreateWindowExW( // vytvorenie hl okna
        0,
        CLASSNAME,
        L"Moja Appka",
        WS_POPUP,
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
        RECT Main_rect;
        GetClientRect(hwnd, &Main_rect);
        // vytvori tlacidlo button->co to ma byt....zobraz text->text na tlacidle...WS ->styly a vyzor... poloha a velkost...
        Button[0] = CreateWindowW(L"BUTTON", L"Vitajte pre pokracovanie klikni", WS_CHILD | WS_VISIBLE, 600, 250, 400, 200, hwnd, (HMENU)(ID_BUTTONS), NULL, NULL);
        Button[14] = CreateWindowW(L"BUTTON", L"", WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, Main_rect.right - 50, 0, 50, 30, hwnd, (HMENU)(ID_BUTTONS + 14), NULL, NULL);
        Button[15] = CreateWindowW(L"BUTTON", L"[]", WS_CHILD | WS_VISIBLE, Main_rect.right - 100, 0, 50, 30, hwnd, (HMENU)(ID_BUTTONS + 15), NULL, NULL);
        Button[16] = CreateWindowW(L"BUTTON", L"-", WS_CHILD | WS_VISIBLE, Main_rect.right - 150, 0, 50, 30, hwnd, (HMENU)(ID_BUTTONS + 16), NULL, NULL);
        break;
    case WM_COMMAND:
    {
        Render_Page(Page_Num, lparam, wparam);
        if (LOWORD(wparam) == ID_BUTTONS + 14)
        {
            PostQuitMessage(0);
        }
        if (LOWORD(wparam) == ID_BUTTONS + 15)
        {
            if (IsZoomed(hwnd))
            {
                ShowWindow(hwnd, SW_RESTORE);
            }
            else
            {
                ShowWindow(hwnd, SW_MAXIMIZE);
            }
        }
        if (LOWORD(wparam) == ID_BUTTONS + 16)
        {
            ShowWindow(hwnd, SW_MINIMIZE);
        }
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0); // zavrie appku
        break;
    case WM_PAINT:
    {
        HDC hdc;
        PAINTSTRUCT Ps;
        RECT Main_Rect;
        GetClientRect(hwnd, &Main_Rect);
        hdc = BeginPaint(hwnd, &Ps);
        Border(hdc, Main_Rect);
        Paint(hdc);
        if (Buttons_State[2] == true)
        {
            SetTextColor(hdc, RGB(255, 255, 255)); // biely text
            SetBkMode(hdc, TRANSPARENT);
            TextOutW(hdc, 500, 500, L"Oblast mysi = 1", 16);
        }
        else
        {
            SetTextColor(hdc, RGB(255, 255, 255)); // biely text
            SetBkMode(hdc, TRANSPARENT);
            TextOutW(hdc, 500, 500, L"Oblast mysi = 0", 16);
        }
        EndPaint(hwnd, &Ps);
        break;
    }
    case WM_ACTIVATE:
    {
        if (LOWORD(wparam) != WA_INACTIVE)
            InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
        break;
    }
    case WM_NCHITTEST:
    {
        LRESULT hit = DefWindowProc(hwnd, WM_NCHITTEST, wparam, lparam);

        if (hit == HTCLIENT)
        {
            POINT cursor;
            cursor.x = GET_X_LPARAM(lparam);
            cursor.y = GET_Y_LPARAM(lparam);
            ScreenToClient(hwnd, &cursor);

            int border = 8; // hrúbka okraja na resizovanie

            RECT rect;
            GetClientRect(hwnd, &rect);

            bool left = cursor.x < border;
            bool right = cursor.x > rect.right - border;
            bool top = cursor.y < border;
            bool bottom = cursor.y > rect.bottom - border;

            if (left && top)
                return HTTOPLEFT;
            if (right && top)
                return HTTOPRIGHT;
            if (left && bottom)
                return HTBOTTOMLEFT;
            if (right && bottom)
                return HTBOTTOMRIGHT;
            if (left)
                return HTLEFT;
            if (right)
                return HTRIGHT;
            if (top)
                return HTTOP;
            if (bottom)
                return HTBOTTOM;

            // Vlastná title bar oblasť (napr. 30px)
            if (cursor.y < 30)
                return HTCAPTION;
        }

        return hit;
    }

    case WM_SIZE:
        RECT Resize_Rect;
        GetClientRect(hwnd, &Resize_Rect);
        switch (wparam)
        {
        case SIZE_MAXIMIZED:
        {
            MoveWindow(Button[15], Resize_Rect.right - 100, 0, 50, 30, true);
            MoveWindow(Button[14], Resize_Rect.right - 50, 0, 50, 30, true);
            MoveWindow(Button[16], Resize_Rect.right - 150, 0, 50, 30, true);
            break;
        }
        case SIZE_RESTORED:
        {
            MoveWindow(Button[15], Resize_Rect.right - 100, 0, 50, 30, true);
            MoveWindow(Button[14], Resize_Rect.right - 50, 0, 50, 30, true);
            MoveWindow(Button[16], Resize_Rect.right - 150, 0, 50, 30, true);
            break;
        }
        case SIZE_MINIMIZED:
        {
            {
                MoveWindow(Button[15], Resize_Rect.right - 100, 0, 50, 30, true);
                MoveWindow(Button[14], Resize_Rect.right - 50, 0, 50, 30, true);
                MoveWindow(Button[16], Resize_Rect.right - 150, 0, 50, 30, true);
                break;
            }
        }
        }
        break;

    case WM_KEYDOWN:
        Render_Page_Keyboard(wparam, lparam);
        break;
        // Tvorba vlastneho stylu tlacidla
    case WM_DRAWITEM:
    {
        Border_Buttons_Draw(hwnd, lparam);
        break;
    }
    case WM_MOUSEMOVE:
    {
        Border_Buttons_Funct(hwnd, lparam);
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
        Welcome_Page(wparam, lparam);
        break;
    case 1:
        if (!Page)
        {
            Page = new Main_Page(hwnd);
        }
        Page->Buttons_Function(Page_Num, Button, Buttons_State, wparam, lparam);
        Page = nullptr;
        Page = new Data_Struct_Page(hwnd);
        InvalidateRect(hwnd, NULL, true);
        UpdateWindow(hwnd);
        break;
    case 2:
        if (!Page)
        {
            Page = new Data_Struct_Page(hwnd);
        }
        Page->Buttons_Function(Page_Num, Button, Buttons_State, wparam, lparam);
        break;
    }
}

void Moja_Apka::Welcome_Page(WPARAM wparam, LPARAM lparam)
{
    switch (LOWORD(wparam))
    {
    case (ID_BUTTONS):
        DestroyWindow(Button[0]);
        Page = new Main_Page(hwnd);
        Page->Create_WindowW(Button, ID_BUTTONS);
        Page_Num = 1;
    }
}

void Moja_Apka::Paint(HDC hdc)
{
    switch (Page_Num)
    {
    case 2:
        Page->Cout_Create(hdc);
        Page->Cout_Button_2(hdc);
        if (Buttons_State[0])
        {
            Page->Cout_Button_1(hdc);
        }

        break;
    }
}

void Moja_Apka::Render_Page_Keyboard(WPARAM wparam, LPARAM lparam)
{
    switch (Page_Num)
    {
    case 0:
    {
        break;
    }
    case 1:
    {
    }
    case 2:
    {
        if (!Page)
        {
            Page = new Data_Struct_Page(hwnd);
        }
        Page->Key_Board_Func(wparam, lparam, ID_BUTTONS, Button);
        break;
    }
    }
}

void Moja_Apka::Border(HDC hdc, RECT Main_Rect)
{
    RECT Title_bar = {0, 0, Main_Rect.right, 30};
    HBRUSH TB_Color = CreateSolidBrush(RGB(30, 30, 30));
    FillRect(hdc, &Title_bar, TB_Color);
    DeleteObject(TB_Color);

    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    TextOutW(hdc, 10, 8, L"Moja Aplikacia", 15);

    // RECT close_btn = {Main_Rect.right - 50, 0, Main_Rect.right, 30};
    // HBRUSH Close_Btn_Color;
    // Close_Btn_Color = CreateSolidBrush(RGB(204, 0, 0));
    // FillRect(hdc, &close_btn, Close_Btn_Color);
    // DeleteObject(Close_Btn_Color);
    // SetTextColor(hdc, RGB(255, 255, 255));
    // TextOutW(hdc, Main_Rect.right - 50, 0, L"X", 1);
}

bool Moja_Apka::Border_Buttons_Draw(HWND hwnd, LPARAM lparam)
{
    LPDRAWITEMSTRUCT Button_X = (LPDRAWITEMSTRUCT)lparam;
    if (Button_X->CtlID == ID_BUTTONS + 14)
    {
        HBRUSH BTN_1_Color;

        if (Buttons_State[2] == true)
        {
            BTN_1_Color = CreateSolidBrush(RGB(204, 0, 0));
        }
        else
        {
            BTN_1_Color = CreateSolidBrush(RGB(30, 30, 30));
        }
        FillRect(Button_X->hDC, &Button_X->rcItem, BTN_1_Color);
        DeleteObject(BTN_1_Color);

        SetTextColor(Button_X->hDC, RGB(244, 244, 244));
        SetBkMode(Button_X->hDC, TRANSPARENT);
        DrawTextW(Button_X->hDC, L"X", -1, &Button_X->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        return true;
    }
    if (Button_X->CtlID == ID_BUTTONS + 15)
    {
        HBRUSH BTN_1_Color;

        if (Buttons_State[3] == true)
        {
            BTN_1_Color = CreateSolidBrush(RGB(204, 0, 0));
        }
        else
        {
            BTN_1_Color = CreateSolidBrush(RGB(30, 30, 30));
        }
        FillRect(Button_X->hDC, &Button_X->rcItem, BTN_1_Color);
        DeleteObject(BTN_1_Color);

        SetTextColor(Button_X->hDC, RGB(244, 244, 244));
        SetBkMode(Button_X->hDC, TRANSPARENT);
        DrawTextW(Button_X->hDC, L"X", -1, &Button_X->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        return true;
    }
    if (Button_X->CtlID == ID_BUTTONS + 16)
    {
        HBRUSH BTN_1_Color;

        if (Buttons_State[4] == true)
        {
            BTN_1_Color = CreateSolidBrush(RGB(204, 0, 0));
        }
        else
        {
            BTN_1_Color = CreateSolidBrush(RGB(30, 30, 30));
        }
        FillRect(Button_X->hDC, &Button_X->rcItem, BTN_1_Color);
        DeleteObject(BTN_1_Color);

        SetTextColor(Button_X->hDC, RGB(244, 244, 244));
        SetBkMode(Button_X->hDC, TRANSPARENT);
        DrawTextW(Button_X->hDC, L"X", -1, &Button_X->rcItem, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

        return true;
    }
}

void Moja_Apka::Border_Buttons_Funct(HWND hwnd, LPARAM lparam)
{
    POINT BTN_X = {GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)};
    RECT Main_Window;
    GetClientRect(hwnd, &Main_Window);

    bool inside = (BTN_X.x > Main_Window.right - 52 && BTN_X.y < Main_Window.top + 31);
    if (inside != Buttons_State[2])
    {
        Buttons_State[2] = inside;
        InvalidateRect(hwnd, NULL, TRUE);
        UpdateWindow(hwnd);
    }
}
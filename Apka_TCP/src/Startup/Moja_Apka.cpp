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
    Buttons_State = new bool[6];
    for (int i{}; i < 5; i++)
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
        HDC hdc;
        PAINTSTRUCT Ps;
        RECT Main_Rect;
        GetClientRect(hwnd, &Main_Rect);
        hdc = BeginPaint(hwnd, &Ps);
        Border(hdc, Main_Rect);
        Paint(hdc);
        Draw_Buttons_Border(hwnd, lparam, hdc);
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
            {
                RECT rcButtons = {rect.right - 150, 0, rect.right, 30}; // pravý horný pás s tlačidlami
                if (!PtInRect(&rcButtons, cursor))
                    return HTCAPTION; // zvyšok horného pásu na ťahanie
            }
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
            InvalidateRect(hwnd, &Resize_Rect, TRUE);
            UpdateWindow(hwnd);
            break;
        }
        case SIZE_RESTORED:
        {
            InvalidateRect(hwnd, &Resize_Rect, TRUE);
            UpdateWindow(hwnd);
            break;
        }
        case SIZE_MINIMIZED:
        {
            {
                InvalidateRect(hwnd, &Resize_Rect, TRUE);
                UpdateWindow(hwnd);
                break;
            }
        }
        }
        break;

    case WM_KEYDOWN:
        Render_Page_Keyboard(wparam, lparam);
        break;
        // Tvorba vlastneho stylu tlacidla
    // case WM_DRAWITEM:
    // {
    //     Border_Buttons_Draw(hwnd, lparam);
    //     break;
    // }
    case WM_MOUSEMOVE:
    {
        Mouse_Cursor_Move(hwnd, lparam);
    }
    break;
    case WM_LBUTTONDOWN:
        L_BTN_Click(hwnd);
        break;
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
    RECT Title_bar = {0, 0, Main_Rect.right - 150, 30};
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

void Moja_Apka::Draw_Buttons_Border(HWND hwnd, LPARAM lparam, HDC hdc)
{
    RECT Main_window;
    GetClientRect(hwnd, &Main_window);

    HBRUSH BTN_X_Color;
    HBRUSH BTN_MAX_MIN_Color;
    HBRUSH BTN_MINIMIZE_Color;
    if (Buttons_State[2] == true)
    {
        BTN_X_Color = CreateSolidBrush(RGB(204, 0, 0));
    }
    else
    {
        BTN_X_Color = CreateSolidBrush(RGB(30, 30, 30));
    }
    if (Buttons_State[3])
    {
        BTN_MAX_MIN_Color = CreateSolidBrush(RGB(30, 40, 40));
    }
    else
    {
        BTN_MAX_MIN_Color = CreateSolidBrush(RGB(30, 30, 30));
    }
    if (Buttons_State[4])
    {
        BTN_MINIMIZE_Color = CreateSolidBrush(RGB(30, 40, 40));
    }
    else
    {
        BTN_MINIMIZE_Color = CreateSolidBrush(RGB(30, 30, 30));
    }
    RECT BTN_X_Rect = {Main_window.right - 50, 0, Main_window.right, 30};
    RECT BTN_MAX_MIN_Rect = {Main_window.right - 100, 0, Main_window.right - 50, 30};
    RECT BTN_MINIMIZE_Rect = {Main_window.right - 150, 0, Main_window.right - 100, 30};
    FillRect(hdc, &BTN_X_Rect, BTN_X_Color);
    FillRect(hdc, &BTN_MAX_MIN_Rect, BTN_MAX_MIN_Color);
    FillRect(hdc, &BTN_MINIMIZE_Rect, BTN_MINIMIZE_Color);

    HFONT BTN_FONT = CreateFontW(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI");
    HFONT BTN_HOLD_FONT = (HFONT)SelectObject(hdc, BTN_FONT);

    HPEN X_PEN = CreatePen(PS_SOLID, 3, RGB(205, 205, 205));
    HPEN X_HOLD_PEN = (HPEN)SelectObject(hdc, X_PEN);

    DrawTextW(hdc, L"X", -1, &BTN_X_Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    DrawTextW(hdc, L"[]", -1, &BTN_MAX_MIN_Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    DrawTextW(hdc, L"_", -1, &BTN_MINIMIZE_Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    SelectObject(hdc, BTN_HOLD_FONT);
    SelectObject(hdc, X_HOLD_PEN);
    SelectObject(hdc, BTN_FONT);
    DeleteObject(BTN_X_Color);
}

void Moja_Apka::Mouse_Cursor_Move(HWND hwnd, LPARAM lparam)
{
    POINT Mouse_Move = {GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)};
    RECT Main_Window;
    GetClientRect(hwnd, &Main_Window);

    bool IN_X = (Mouse_Move.x > Main_Window.right - 50 && Mouse_Move.y < 30);
    bool IN_RESTORE = (Mouse_Move.x > Main_Window.right - 100 && Mouse_Move.x < Main_Window.right - 50 && Mouse_Move.y < 30);
    bool IN_MINIMIZE = (Mouse_Move.x > Main_Window.right - 150 && Mouse_Move.x < Main_Window.right - 100 && Mouse_Move.y < 30);
    
    
        if (IN_X != Buttons_State[2])
        {
            Buttons_State[2] = IN_X;
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);
        }
        else if(Buttons_State[2])
        {
            Buttons_State[2] = false;
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);
        }
        if (IN_RESTORE != Buttons_State[3])
        {
            Buttons_State[3] = IN_RESTORE;
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);
        }
        else if(Buttons_State[3])
        {
            Buttons_State[3] = false;
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);
        }
        if (IN_MINIMIZE != Buttons_State[4])
        {
            Buttons_State[4] = IN_MINIMIZE;
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);
        }
        else if (Buttons_State[4])
        {
            Buttons_State[4] = false;
            InvalidateRect(hwnd, NULL, TRUE);
            UpdateWindow(hwnd);
        }

}

void Moja_Apka::L_BTN_Click(HWND hwnd)
{
    if (Buttons_State[2])
    {
        PostQuitMessage(0);
    }
    if (Buttons_State[3])
    {
        if (IsZoomed(hwnd))
        {
           ShowWindow(hwnd, SW_RESTORE);
           Buttons_State[3] = false;
        }
        else
        {
            ShowWindow(hwnd,SW_MAXIMIZE);
            Buttons_State[3] = false;
        }
    }
    if(Buttons_State[4])
    {
        ShowWindow(hwnd,SW_MINIMIZE);
        Buttons_State[4] = false;
    }
}
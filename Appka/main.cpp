#include <windows.h>
#define ID_BUTTON_SHOW_TEXT 1
#define ID_BUTTON_END 2
#define ID_EDIT 3

wchar_t Buffer_For_Text [300];

LRESULT CALLBACK WindowProc(HWND hwnd,UINT umsg,WPARAM wparam,LPARAM lparam){
    switch (umsg){
       case WM_CREATE:
          CreateWindowW(L"BUTTON",L"Zobraz text",WS_VISIBLE|WS_CHILD,500,10,150,100,hwnd,(HMENU)ID_BUTTON_SHOW_TEXT,NULL,NULL);
          CreateWindowW(L"BUTTON",L"Koniec",WS_VISIBLE|WS_CHILD,1000,10,150,100,hwnd,(HMENU)ID_BUTTON_END,NULL,NULL);
          CreateWindowW(L"EDIT",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|ES_LEFT,10,10,150,100,hwnd,(HMENU)ID_EDIT,NULL,NULL);
        break;
        case WM_COMMAND:
           switch (LOWORD(wparam))
           {
           case ID_BUTTON_SHOW_TEXT:
               {
               HWND h_Edit = GetDlgItem(hwnd,ID_EDIT);
               GetWindowTextW(hwnd,Buffer_For_Text,300);
               MessageBoxW(hwnd,Buffer_For_Text,L"Sprava",MB_OK|MB_ICONINFORMATION);
               break;}
            case ID_BUTTON_END:
               PostQuitMessage(0);
            break;
           }
           break;
           case WM_DESTROY:
           PostQuitMessage(0);
           break;
           default:
           return DefWindowProc(hwnd,umsg,wparam,lparam);
           break;
}
return 0;
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow){
     const wchar_t CLASSNAME[] =  L"MojeOknoTrieda";

     WNDCLASSW wc {};
     wc.lpfnWndProc = WindowProc;
     wc.hInstance = hInstance;
     wc.lpszClassName = CLASSNAME;
     wc.hbrBackground = (HBRUSH)(COLOR_WINDOW +5);
     wc.hCursor =  LoadCursor(NULL,IDC_ARROW);

     RegisterClassW(&wc);

       HWND hwnd = CreateWindowExW(
        0,
        CLASSNAME,
        Buffer_For_Text,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 250,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}



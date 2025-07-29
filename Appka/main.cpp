#include <windows.h>
#define ID_BUTTON_SHOW_TEXT 1
#define ID_BUTTON_END 2

LRESULT CALLBACK WindowProc(HWND hwnd,UINT umsg,WPARAM wparam,LPARAM lparam){
    switch (umsg){
       case WM_CREATE:
          CreateWindow(L"BUTTON",L"Zobraz text",WS_VISIBLE|WS_CHILD,100,100,150,10,hwnd,(HMENU)ID_BUTTON_SHOW_TEXT,NULL,NULL);
          CreateWindow(L"BUTTON",L"Koniec",WS_VISIBLE|WS_CHILD,100,100,150,10,hwnd,(HMENU)ID_BUTTON_SHOW_TEXT,NULL,NULL);
        break;
        case WM_COMMAND:
           switch (LOWORD(wparam))
           {
           case ID_BUTTON_SHOW_TEXT:
               MessageBox(hwnd,L"Hallo world",L"Sprava",MB_OK|MB_ICONINFORMATION);
               break;
            case ID_BUTTON_END:
               PostQuitMessage(0);
            break;
           }
           case WM_DESTROY:
           PostQuitMessage(0);
           break;
           default:
           return DefWindowProc(hwnd,umsg,wparam,lparam);
           break;
}
}
int main () {
    
    return 0;
}


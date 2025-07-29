#include <windows.h>
#define ID_BUTTON_SHOW_TEXT 1
#define ID_BUTTON_END 2

LRESULT CALLBACK WindowProc(HWND hwnd,UINT umsg,WPARAM wparam,LPARAM lparam){
    switch (umsg){
       case WM_CREATE:
          CreateWindow("BUTTON","Zobraz text",WS_VISIBLE|WS_CHILD,100,100,150,10,hwnd,(HMENU)ID_BUTTON_SHOW_TEXT,NULL,NULL);

    
}
}
int main () {
    
    return 0;
}



#include "Moja_Apka.h"

// histance je unikatne cislo okna
// Histance hprevinstance je pre zastarale systemy moze byt null
// lpwstr-> retazec priradeny pri vytvarani
// ncmdshow-> ako sa ma hl okno zobrazovat
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{           
    Moja_Apka App(hInstance);                                       // main funkcia
    
    
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
/* for(int i{};i < 5;i++){
            int j{};
               if(i == 0){j = 0;}
               else if(i == 1){j = 1;}
               else if(i == 2){j = 0;}
               else if(i == 3){j = 0;}
               else if(i == 4){j = 0;}
        CreateWindow(Buttons_Funcionallity[j], Buttons_Names [i],  WS_CHILD|WS_VISIBLE, Button_X[i], Butoon_Y[i], 150, 100, hwnd, (HMENU)(ID_BUTTONS+i), NULL, NULL);
        }*/
//pc home

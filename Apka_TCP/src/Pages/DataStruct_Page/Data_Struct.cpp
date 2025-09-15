#include "Data_Struct.h"

Data_Struct_Page::Data_Struct_Page(){
    Windows_Names = new wchar_t *[5]{{L"Paint"}};
    Windows_CLASS = new wchar_t *[5]{{L"BUTTON"}};
    Number_Of_Windows = new int{1};
    Windows_PositionsX = new int[1]{10};
    Windows_PositionsY = new int[1]{10};
    Windows = new HWND[10];
    Buttons_Bools = new bool[5];
}

Data_Struct_Page::~Data_Struct_Page(){
    
}

void Data_Struct_Page::Cout(HWND Main_hwnd){
     PAINTSTRUCT ps;
     HDC hdc;
     TextOutW(hdc,200,200,L"AHOJ",20);


}

void Data_Struct_Page:: Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,HWND Main_hwnd){
    enum BUTTONS_ID{Paint = 10000};
    switch(LOWORD(wparam)){
        case Paint:
            if(Buttons_Bools[0]){
               Cout(Main_hwnd);
               Buttons_Bools[0] = false;
            }
            else {
              Buttons_Bools[0] = true;

            }
    }
}
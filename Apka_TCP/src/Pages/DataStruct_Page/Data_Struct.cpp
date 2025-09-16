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

void Data_Struct_Page::Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON)
{
    
    for (int i{}; i < *Number_Of_Windows; i++)
    {
         Buttons[i] = CreateWindowW(Windows_CLASS[i], Windows_Names[i], WS_CHILD | WS_VISIBLE, Windows_PositionsX[i], Windows_PositionsY[i], 200, 100, Main_Hwnd, (HMENU)(BUTTON + i), NULL, NULL);
    }
   
    
}

void Data_Struct_Page::Cout(HDC hdc){

}

void Data_Struct_Page:: Buttons_Function(LPARAM lparam,WPARAM wparam,int &page_num,HWND *Buttons,HWND Main_hwnd,bool *Buttons_State){
    enum BUTTONS_ID{Paint = 10000};
     switch(LOWORD(wparam)){
        case Paint:
             if(Buttons_State[0]){
               Buttons_State[0] = false;
             }
             else if(!Buttons_State[0]){
               Buttons_State[0] = true;
             }
             break;
     }
}
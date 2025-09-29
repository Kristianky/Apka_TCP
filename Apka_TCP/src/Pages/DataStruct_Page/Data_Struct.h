#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "Pages.h"


class Data_Struct_Page:public Pages{
     private:
         int *Sparse_Matrix;
     public:
         Data_Struct_Page();
         void Create_WindowW(HWND *Buttons,HWND Main_Hwnd,int BUTTON) override;
         virtual ~Data_Struct_Page();
         virtual void Buttons_Function(LPARAM lparam,WPARAM wparam,HWND hwnd,int &page_num,HWND *Buttons,HWND Main_hwnd,bool *Buttons_state) override;   
         virtual void Cout(HDC hdc) override;
         void Create_SparseMatrix(int Number_Of_Data,int x, int y);
};

void Data_Struct_Page::Create_SparseMatrix(int Number_Of_Data,int x, int y){
     Sparse_Matrix = new int[Number_Of_Data];
}
#endif
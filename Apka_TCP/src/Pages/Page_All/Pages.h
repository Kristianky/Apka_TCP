

#ifndef _PAGES_H_
#define _PAGES_H_

#define ID_BUTTONS 10000
#define ID_EDIT 20000

#include "Sparse_Matrix.h"
#include "Polynomial.h"
#include <windows.h>
#include <string>
#include <vector>

struct Edit_Size
{
   std::vector<int> Size_X;
   std::vector<int> Size_Y;
};
class Pages
{
protected:
   int Number_Of_Buttons;
   int Number_Of_Edit;
   int *Buttons_PositionsX;
   int *Buttons_PositionsY;
   int *Edit_Postion_X;
   int *Edit_Postion_Y;
   wchar_t *Page_Name;
   HWND Main_hwnd;
   /** @brief
    -Buffer_Edit[0] = Lenght_X
    -Buffer_Edit[1] = Lenght_Y

    -Buffer_Edit[2] = Data_Lenght
    -Buffer_Edit[3] = Data

    -Buffer_Edit[4] = Data_Position_X
    -Buffer_Edit[5] = Data_Postion_Y
    */
   wchar_t **Buffer_Edit;
   std::wstring Buffer_Data;
   std::wstring *Buffer_Message_Box;
   Sparse_Matrix Sparse_matrix;
   Sparse_Matrix One;
   Sparse_Matrix Two;
   int *Size_Of_Buffers;
   int *Indexes;
   bool *Bools;
   Pollynom Polly;
   RECT Main_Rect;
   Edit_Size EditSize;
public:
   Pages() = default;
   Pages(HWND hwnd);
   virtual ~Pages();
   virtual void Create_ButtonsW(HWND *Buttons) = 0;
   virtual void Create_EditW(HWND *Edit_Boxes) = 0;
   virtual void Destroy_WindowW(HWND *Window,int Size);
   virtual void Buttons_Function(int &page_num, HWND *Buttons,HWND *Edit_Boxes, bool *Buttons_state, WPARAM wparam, LPARAM lparam) = 0;
   virtual void Cout_Button_1(HDC hdc) = 0;
   virtual void Cout_Button_2(HDC hdc) = 0;
   virtual void Cout_Button_3(HDC hdc) = 0;
   virtual void Cout_Create(HDC hdc) = 0;
   virtual HWND Get_hwnd() = 0;
   virtual void Key_Board_Func(WPARAM wparam, LPARAM lparam, int ID_Button, HWND *Window) = 0;
   virtual void Add_Sparse_Matrix(Sparse_Matrix &First, Sparse_Matrix &Second, HWND *Buttons) = 0;
   virtual void To_Wstring() = 0;
   virtual void Edit_Box_Paint(HDC hdc) = 0;
};

#endif
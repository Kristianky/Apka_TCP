#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "Pages.h"

class Data_Struct_Page : public Pages
{
public:
    static const wchar_t *Windows_Names[5];
    static const wchar_t *Windows_CLASS[2];
    Data_Struct_Page(HWND hwnd);
    void Create_ButtonsW(HWND *Buttons) override;
    virtual void Create_EditW(HWND *Edit_Boxes) override;
    virtual ~Data_Struct_Page();
    virtual void Buttons_Function(int &page_num, HWND *Buttons,HWND *Edit_Boxes, bool *Buttons_state, WPARAM wparam, LPARAM lparam) override;
    virtual void Cout_Button_1(HDC hdc) override;
    virtual void Cout_Create(HDC hdc) override;
    virtual HWND Get_hwnd() { return Main_hwnd; }
    virtual void Key_Board_Func(WPARAM wparam, LPARAM lparam, int ID_Button, HWND *Window);
    virtual void Cout_Button_2(HDC hdc) override;
    virtual void Add_Sparse_Matrix(Sparse_Matrix &First, Sparse_Matrix &Second, HWND *Buttons) override;
    virtual void To_Wstring() override;
};

#endif
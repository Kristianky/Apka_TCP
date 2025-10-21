#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#include <string>

class Sparse_Matrix{
    private:
     int Size,Lenght_X,Lenght_Y;
     wchar_t **data;
     int *x;
     int *y;
     int Index_Of_Data;
    public:
     void add_data(wchar_t *Buffer,wchar_t *X,wchar_t *Y);
     Sparse_Matrix() = default;
     ~Sparse_Matrix() = default;
     void set_Lenght_X_Y_Size(wchar_t* x,wchar_t* y,wchar_t *Size_Of_Buffer);
     void Print(std::wstring &Buffer_Table,int x);
};



#endif
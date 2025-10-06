#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#include <string>

class Sparse_Matrix{
    private:
     int Size,Lenght_X,Lenght_Y;
     wchar_t *data;
     wchar_t *x;
     wchar_t *y;
    public:
     int add_data(wchar_t *Buffer,wchar_t *size,int Index_OF_Buffer,wchar_t *X,wchar_t *Y);
     Sparse_Matrix() = default;
     Sparse_Matrix(int size,int Lenght_X,int Lenght_Y)
     :Size{size},Lenght_X{Lenght_X},Lenght_Y{Lenght_Y} { data = new wchar_t[size];x = new wchar_t[Lenght_X];y = new wchar_t [Lenght_Y];};
     ~Sparse_Matrix() = default;
     void set_Lenght_X_Y(wchar_t* x,wchar_t* y);
};



#endif
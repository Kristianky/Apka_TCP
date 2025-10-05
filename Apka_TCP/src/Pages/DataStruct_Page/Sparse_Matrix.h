#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#include "Data_Struct.h"

class Sparse_Matrix{
    private:
     int Size,Lenght_X,Lenght_Y;
     wchar_t *data;
     int *x;
     int *y;
    public:
     void add_data(wchar_t *Buffer,wchar_t size);
     Sparse_Matrix(int size,int Lenght_X,int Lenght_Y)
     :Size{size},Lenght_X{Lenght_X},Lenght_Y{Lenght_Y} { data = new wchar_t[size];x = new int[Lenght_X];y = new int [Lenght_Y];};
     ~Sparse_Matrix() = default;
     void set_Lenght_X_Y(wchar_t x,wchar_t y);
};



#endif
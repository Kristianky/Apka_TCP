#include "Sparse_Matrix.h"

int Sparse_Matrix::add_data(wchar_t *Buffer,wchar_t size){
     Size = static_cast<int>(size);
     if (Lenght_X == 0 || Lenght_Y == 0){
        Buffer = new wchar_t[] {L"Lenght X or Y are 0 cant make Table !!"};
        return sizeof(Buffer);
     }
     else
     return 1;
 }

 void Sparse_Matrix::set_Lenght_X_Y(wchar_t x,wchar_t y){
     Lenght_X = static_cast<int>(x);
     Lenght_Y = static_cast<int>(y) + static_cast<int>(x);
 }
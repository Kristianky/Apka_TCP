#include "Sparse_Matrix.h"

void Sparse_Matrix::add_data(wchar_t *Buffer,wchar_t size){
     Size = static_cast<int>(size);
     
 }

 void Sparse_Matrix::set_Lenght_X_Y(wchar_t x,wchar_t y){
     Lenght_X = static_cast<int>(x);
     Lenght_Y = static_cast<int>(y);
 }
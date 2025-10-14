#include "Sparse_Matrix.h"

int Sparse_Matrix::add_data(wchar_t *Buffer,wchar_t *size,int Index_OF_Buffer,wchar_t *X,wchar_t *Y){
     std::wstring Buffer_temp = Buffer,Size_Temp = size, X_Temp = X, Y_temp = Y;
     int Size_Int = std::stoi(Size_Temp);
     int X_Int = std::stoi(X_Temp),Y_Int = std::stoi(Y_temp);
     if (Lenght_X == 0 || Lenght_Y == 0){
        delete Buffer;
        Buffer = new wchar_t[40] {L"Lenght X or Y are 0 cant make Table !!"};
        Buffer_temp = Buffer;
        return Buffer_temp.size() + 1;
     }
     else
      
       
     return 0;
 }

 void Sparse_Matrix::set_Lenght_X_Y(wchar_t* x,wchar_t* y){
     std::wstring X_Temp = x,Y_temp = y;
     Lenght_X = std::stoi(X_Temp);
     Lenght_Y = std::stoi(Y_temp);
 }

 void Sparse_Matrix::Print(std::wstring &Buffer_Table,int index){
    
    for(index;index < Lenght_X;index++){
    for(int index_2{index * Lenght_Y};index_2 < (index + 1 * Lenght_Y);index_2++){
        Buffer_Table += L"0\n0";
    }
    
  

 }}
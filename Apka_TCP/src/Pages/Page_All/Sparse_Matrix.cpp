#include "Sparse_Matrix.h"

void Sparse_Matrix::add_data(wchar_t *Buffer, wchar_t *X, wchar_t *Y)
{
    std::wstring X_Temp = X, Y_temp = Y;
    if(Index_Of_Data !=Size){
    x[Index_Of_Data] = std::stoi(X_Temp);
    y[Index_Of_Data] = std::stoi(Y_temp);
    
    data[Index_Of_Data] = Buffer;
  
    Index_Of_Data++;}
    
  
}

void Sparse_Matrix::set_Lenght_X_Y_Size(wchar_t *x, wchar_t *y, wchar_t *Size_Of_Buffer)
{
    if(Index_Of_Data == Size){
    std::wstring X_Temp = x, Y_temp = y, Size_Temp = Size_Of_Buffer;
    Lenght_X = std::stoi(X_Temp);
    Lenght_Y = std::stoi(Y_temp);
    Size = std::stoi(Size_Temp);
    if(data == nullptr){
        data = new wchar_t*[Size];
    }
    if(Sparse_Matrix::x == nullptr){
        Sparse_Matrix::x = new int[Size + 1];
    }
    if(Sparse_Matrix::y == nullptr){
        Sparse_Matrix::y = new int[Size + 1];
    }
    Index_Of_Data_Paint = 0;
    Index_Of_Data = 0;
}}

void Sparse_Matrix::Print(std::wstring &Buffer_Table,int x)
{
    if(x == 0){
        Buffer_Table = L"   ";
        for(int i{};i < Lenght_Y;i++){
            std::wstring Temp = std::to_wstring(i + 1);
            Buffer_Table += Temp;
            Buffer_Table += L".";
        }
    }
    else{
    if(Index_Of_Data == Size){
    std::wstring X_Position = std::to_wstring(x + 1);
    Buffer_Table = X_Position;
    Buffer_Table += L". ";
    for (int y{}; y < Lenght_Y; y++)
    {
        if(Index_Of_Data == Size){
        if(x  == Sparse_Matrix::x[Index_Of_Data_Paint]   && y  == Sparse_Matrix::y[Index_Of_Data_Paint] - 1 ){
           Buffer_Table += data[Index_Of_Data_Paint];
           Buffer_Table += L" ";
           Index_Of_Data_Paint++;
        }
        else
        Buffer_Table += L"0 ";
        if(Index_Of_Data_Paint == Size){
            Index_Of_Data_Paint = 0;
        }
    }}}
    else 
    Buffer_Table = L"Data is not full";}
}
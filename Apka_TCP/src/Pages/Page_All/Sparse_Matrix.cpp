#include "Sparse_Matrix.h"

void Sparse_Matrix::add_data(wchar_t *Buffer, wchar_t *X, wchar_t *Y)
{
    
    std::wstring X_Temp = X, Y_temp = Y;
    x[Index_Of_Data] = std::stoi(X_Temp);
    y[Index_Of_Data] = std::stoi(Y_temp);
    if(Index_Of_Data == Size){
    data[Index_Of_Data] = Buffer;
    wcscat(data[Index_Of_Data],L" ");
    Index_Of_Data++;
    }
  
}

void Sparse_Matrix::set_Lenght_X_Y_Size(wchar_t *x, wchar_t *y, wchar_t *Size_Of_Buffer)
{
    std::wstring X_Temp = x, Y_temp = y, Size_Temp = Size_Of_Buffer;
    Lenght_X = std::stoi(X_Temp);
    Lenght_Y = std::stoi(Y_temp);
    Size = std::stoi(Size_Temp);
    if(data == nullptr){
        data = new wchar_t*[Size];
    }
    if(Sparse_Matrix::x == nullptr){
        Sparse_Matrix::x = new int[Size];
    }
    if(Sparse_Matrix::y == nullptr){
        Sparse_Matrix::y = new int[Size];
    }
    Index_Of_Data_Paint = 0;
}

void Sparse_Matrix::Print(std::wstring &Buffer_Table,int x)
{
    Buffer_Table = L"";
    for (int y{}; y < Lenght_Y; y++)
    {
        if(x == Sparse_Matrix::x[0] && y == Sparse_Matrix::y[0]){
           Buffer_Table += data[0];
           Index_Of_Data_Paint++;
        }
        else
        Buffer_Table += L"0 ";
    }
}
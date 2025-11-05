#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

#include <string>

class Sparse_Matrix
{
private:
    int Size, Lenght_X, Lenght_Y;
    wchar_t **data;
    int *x;
    int *y;
    int Index_Of_Data;
    int Index_Of_Data_Paint;

public:
    int add_data(const wchar_t *Buffer, const wchar_t *X, const wchar_t *Y);
    void Add_Data_at(int index, int X_temp, int Y_temp, wchar_t *Data_temp);
    Sparse_Matrix();
    ~Sparse_Matrix() = default;
    Sparse_Matrix(const Sparse_Matrix &Other);
    Sparse_Matrix(Sparse_Matrix &&Rhs);
    void set_Lenght_X_Y_Size(wchar_t *x, wchar_t *y, wchar_t *Size_Of_Buffer);
    void Print(std::wstring &Buffer_Table, int x);
    void Reset_Data();
    Sparse_Matrix operator+(const Sparse_Matrix &Rhs) const;
    Sparse_Matrix &operator=(Sparse_Matrix &&Rhs);
    Sparse_Matrix &operator=(const Sparse_Matrix &Rhs);
    int Get_X(int index) const { return x[index]; }
    int Get_Y(int index) const { return y[index]; }
    wchar_t **Get_Data() const { return data; }
    wchar_t *Get_Data_at(int index) const { return data[index]; }
    int Get_Lenght_X() const { return Lenght_X; }
    int Get_Lenght_Y() const { return Lenght_Y; }
    int Get_Size() const { return Size; }
    int *Get_X_Ptr() const { return x; }
    int *Get_Y_Ptr() const { return y; }
    void Set_X_at(int index, int temp) { x[index] = temp; }
    void Set_Y_at(int index, int temp) { y[index] = temp; }
    void Add_Data_at(int index, wchar_t *Temp) { data[index] = Temp; }
    int Get_Index_Of_Data() const { return Index_Of_Data; }
};

#endif
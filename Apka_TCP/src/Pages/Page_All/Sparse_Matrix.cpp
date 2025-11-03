#include "Sparse_Matrix.h"
Sparse_Matrix::Sparse_Matrix(const Sparse_Matrix &Other)
{
    Size = Other.Size;
    Lenght_X = Other.Lenght_X;
    Lenght_Y = Other.Lenght_Y;

    x = new int[Size];
    y = new int[Size];
    data = new wchar_t*[Size];

    for (int i = 0; i < Size; i++)
    {
        x[i] = Other.x[i];
        y[i] = Other.y[i];

        size_t len = wcslen(Other.data[i]) + 1;
        data[i] = new wchar_t[len];
        wcscpy(data[i], Other.data[i]);
    }
}

int Sparse_Matrix::add_data(wchar_t *Buffer, wchar_t *X, wchar_t *Y)
{
    std::wstring X_Temp = X, Y_temp = Y;
    if (Index_Of_Data != Size)
    {
        for (int i{}; i < Index_Of_Data; i++)
        {
            if (std::stoi(X_Temp) == x[i] && std::stoi(Y_temp) == y[i])
            {
                return -1;
            }
        }

        x[Index_Of_Data] = std::stoi(X_Temp);
        y[Index_Of_Data] = std::stoi(Y_temp);

        data[Index_Of_Data] = Buffer;

        Index_Of_Data++;
        return Index_Of_Data;
    }
}

void Sparse_Matrix::set_Lenght_X_Y_Size(wchar_t *x, wchar_t *y, wchar_t *Size_Of_Buffer)
{
    if (Index_Of_Data == Size)
    {
        std::wstring X_Temp = x, Y_temp = y, Size_Temp = Size_Of_Buffer;
        Lenght_X = std::stoi(X_Temp);
        Lenght_Y = std::stoi(Y_temp);
        Size = std::stoi(Size_Temp);
        if (data == nullptr)
        {
            data = new wchar_t *[Size];
        }
        if (Sparse_Matrix::x == nullptr)
        {
            Sparse_Matrix::x = new int[Size + 1];
        }
        if (Sparse_Matrix::y == nullptr)
        {
            Sparse_Matrix::y = new int[Size + 1];
        }
        Index_Of_Data_Paint = 1;
        Index_Of_Data = 0;
    }
}

void Sparse_Matrix::Print(std::wstring &Buffer_Table, int x)
{
    if (x == 0)
    {
        Buffer_Table = L"   ";
        for (int i{}; i < Lenght_Y; i++)
        {
            std::wstring Temp = std::to_wstring(i + 1);
            Buffer_Table += Temp;
            Buffer_Table += L".";
        }
    }
    else
    {
        if (Index_Of_Data == Size)
        {
            Buffer_Table = L"";
            std::wstring X_Position = std::to_wstring(x);
            int Size_Of_X{std::abs(Lenght_X)}, Size_Of_Actual_X{std::abs(x)}, count_X{}, count_Actual_X{};
            while (Size_Of_Actual_X > 0)
            {
                Size_Of_Actual_X /= 10;
                count_Actual_X++;
            }
            while (Size_Of_X > 0)
            {
                Size_Of_X /= 10;
                count_X++;
            }
            while (count_X != count_Actual_X)
            {
                Buffer_Table += L"0";
                count_Actual_X++;
            }
            Buffer_Table += X_Position;
            Buffer_Table += L". ";
            for (int y{}; y < Lenght_Y; y++)
            {
                if (Index_Of_Data == Size)
                {
                    if (x == Sparse_Matrix::x[Index_Of_Data_Paint] && y == Sparse_Matrix::y[Index_Of_Data_Paint])
                    {
                        Buffer_Table += data[Index_Of_Data_Paint];
                        Buffer_Table += L" ";
                        Index_Of_Data_Paint++;
                    }
                    else
                        Buffer_Table += L"0 ";
                    if (Index_Of_Data_Paint == Size)
                    {
                        Index_Of_Data_Paint = 0;
                    }
                }
            }
        }
        else
            Buffer_Table = L"Data is not full";
    }
}
void Sparse_Matrix::Reset_Data()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
    if (x != nullptr)
    {
        delete[] x;
        x = nullptr;
    }
    if (y != nullptr)
    {
        delete[] y;
        y = nullptr;
    }
}

Sparse_Matrix &Sparse_Matrix::operator=(Sparse_Matrix &&Rhs)
{
    if (this == &Rhs)
    {
        return *this;
    }
    delete[] this->data;
    delete[] this->x;
    delete[] this->y;
    this->Size = Rhs.Get_Size();
    this->Lenght_X = Rhs.Get_Lenght_X();
    this->Lenght_Y = Rhs.Get_Lenght_Y();
    this->x = Rhs.Get_X_Ptr();
    this->y = Rhs.Get_Y_Ptr();
    this->data = Rhs.Get_Data();

    Rhs.data = nullptr;
    Rhs.x = nullptr;
    Rhs.y = nullptr;
    Rhs.Size = 0;
    return *this;
}

Sparse_Matrix Sparse_Matrix::operator+(const Sparse_Matrix &Rhs) const
{
    Sparse_Matrix Temp;
    if (this->Get_Lenght_X() == Rhs.Get_Lenght_X() && this->Get_Lenght_Y() == Rhs.Get_Lenght_Y())
    {
        int Index{}, i{}, j{}, k{};
        int *X_Temp = new int[Get_Lenght_X()];
        int *Y_Temp = new int[Get_Lenght_Y()];
        int Size_Temp = this->Size + Rhs.Get_Size();
        while (Index < Size_Temp)
        {
            if (this->x[i] < Rhs.Get_X(j))
            {
                Temp.Add_Data_at(k, this->Get_X(i), this->Get_Y(i), this->Get_Data_at(i));
                i++;
                k++;
            }
            if (this->x[i] > Rhs.Get_X(j))
            {
                Temp.Add_Data_at(k, Rhs.Get_X(j), Rhs.Get_Y(j), Rhs.Get_Data_at(j));
                j++;
                k++;
            }
            else
            {
                if (this->y[i] < Rhs.Get_Y(j))
                {
                    Temp.Add_Data_at(k, this->x[i], this->y[i], this->Get_Data_at(i));
                    i++;
                    k++;
                }
                else if (this->y[i] > Rhs.Get_Y(j))
                {
                    Temp.Add_Data_at(k, Rhs.Get_X(j), Rhs.Get_Y(j), Rhs.Get_Data_at(j));
                    j++;
                    k++;
                }
                else
                {
                    std::wstring Add_Temp_i = this->data[i], Add_Temp_j = Rhs.Get_Data_at(j);
                    int Temp_i{}, Temp_j{};
                    Temp_i = std::stoi(Add_Temp_i);
                    Temp_j = std::stoi(Add_Temp_j);
                    Temp_i += Temp_j;
                    Add_Temp_i = std::to_wstring(Temp_i);
                    wcscpy(this->data[i], Add_Temp_i.c_str());
                    Temp.Add_Data_at(k, this->Get_X(i), this->Get_Y(i), this->data[i]);
                    k++;
                    i++;
                    j++;
                }
            }
        }
    }
    return Temp;
}

void Sparse_Matrix::Add_Data_at(int index, int X_Temp, int Y_Temp, wchar_t *Data_Temp)
{
    data[index] = Data_Temp;
    x[index] = X_Temp;
    y[index] = Y_Temp;
}
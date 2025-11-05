#include "Sparse_Matrix.h"
Sparse_Matrix::Sparse_Matrix()
{
    data = nullptr;
    x = nullptr;
    y = nullptr;
    Index_Of_Data = 0;
    Size = 0;
    Lenght_X = 0;
    Lenght_Y = 0;
}
Sparse_Matrix::Sparse_Matrix(const Sparse_Matrix &Other)
{
    Size = Other.Size;
    Lenght_X = Other.Lenght_X;
    Lenght_Y = Other.Lenght_Y;
    Index_Of_Data = Other.Get_Index_Of_Data();

    x = new int[Size];
    y = new int[Size];
    data = new wchar_t *[Size];

    for (int i = 0; i < Size; i++)
    {
        x[i] = Other.x[i];
        y[i] = Other.y[i];

        size_t len = wcslen(Other.data[i]) + 1;
        data[i] = new wchar_t[len];
        wcscpy(data[i], Other.data[i]);
    }
}

Sparse_Matrix::Sparse_Matrix(Sparse_Matrix &&Rhs)
    : data{Rhs.Get_Data()}, x{Rhs.Get_X_Ptr()}, y{Get_Y_Ptr()}, Index_Of_Data{Rhs.Index_Of_Data}, Lenght_X{Rhs.Get_Lenght_X()}, Lenght_Y{Rhs.Get_Lenght_Y()}
{
    Rhs.data = nullptr;
    Rhs.x = nullptr;
    Rhs.y = nullptr;
}

int Sparse_Matrix::add_data(const wchar_t *Buffer, const wchar_t *X, const wchar_t *Y)
{
    std::wstring X_Temp = X, Y_temp = Y, Buffer_Temp;
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

        Buffer_Temp = Buffer;
        data[Index_Of_Data] = new wchar_t[Buffer_Temp.size() + 1];
        wcscpy(data[Index_Of_Data], Buffer_Temp.c_str());

        Index_Of_Data++;
        return Index_Of_Data;
    }
    return -1;
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

Sparse_Matrix &Sparse_Matrix::operator=(const Sparse_Matrix &Rhs)
{
    if (this == &Rhs)
        return *this;

    // Uvoľni staré
    for (int i = 0; i < Index_Of_Data; i++)
        delete[] data[i];
    delete[] data;
    delete[] x;
    delete[] y;

    // Skopíruj meta
    Size = Rhs.Size;
    Lenght_X = Rhs.Lenght_X;
    Lenght_Y = Rhs.Lenght_Y;
    Index_Of_Data = Rhs.Index_Of_Data;

    // Alokuj nové pole
    x = new int[Size];
    y = new int[Size];
    data = new wchar_t *[Size];

    // Skopíruj obsah
    for (int i = 0; i < Index_Of_Data; i++)
    {
        x[i] = Rhs.x[i];
        y[i] = Rhs.y[i];

        size_t len = wcslen(Rhs.data[i]) + 1;
        data[i] = new wchar_t[len];
        wcscpy(data[i], Rhs.data[i]);
    }

    return *this;
}

Sparse_Matrix &Sparse_Matrix::operator=(Sparse_Matrix &&Rhs)
{
    if (this == &Rhs)
    {
        return *this;
    }
    for (int i{}; i < Index_Of_Data; i++)
    {
        delete[] data[i];
    }
    delete[] x;
    delete[] y;
    Index_Of_Data = Rhs.Index_Of_Data;
    Lenght_X = Rhs.Lenght_X;
    Lenght_Y = Rhs.Lenght_Y;
    data = Rhs.data;
    x = Rhs.x;
    y = Rhs.y;
    return *this;
}

Sparse_Matrix Sparse_Matrix::operator+(const Sparse_Matrix &Rhs) const
{
    Sparse_Matrix Temp;

    if (Lenght_X != Rhs.Lenght_X || Lenght_Y != Rhs.Lenght_Y)
        return Temp;

    Temp.Lenght_X = Lenght_X;
    Temp.Lenght_Y = Lenght_Y;

    Temp.Size = Size + Rhs.Size;
    Temp.x = new int[Temp.Size];
    Temp.y = new int[Temp.Size];
    Temp.data = new wchar_t*[Temp.Size];

    int i = 0, j = 0, k = 0;

    // 1️⃣ Merge
    while (i < Size && j < Rhs.Size)
    {
        if (x[i] < Rhs.x[j] || (x[i] == Rhs.x[j] && y[i] < Rhs.y[j]))
        {
            Temp.Add_Data_at(k++, x[i], y[i], data[i]);
            i++;
        }
        else if (Rhs.x[j] < x[i] || (Rhs.x[j] == x[i] && Rhs.y[j] < y[i]))
        {
            Temp.Add_Data_at(k++, Rhs.x[j], Rhs.y[j], Rhs.data[j]);
            j++;
        }
        else // rovnaká pozícia (x,y)
        {
            int a = std::stoi(data[i]);
            int b = std::stoi(Rhs.data[j]);
            int s = a + b;

            std::wstring ws = std::to_wstring(s);
            wchar_t *buf = new wchar_t[ws.size()+1];
            wcscpy(buf, ws.c_str());

            Temp.Add_Data_at(k++, x[i], y[i], buf);

            i++;
            j++;
        }
    }

    // 2️⃣ Dopíš zvyšok súčasnej matice
    while (i < Size)
        Temp.Add_Data_at(k++, x[i], y[i], data[i++]);

    // 3️⃣ Dopíš zvyšok Rhs
    while (j < Rhs.Size)
        Temp.Add_Data_at(k++, Rhs.x[j], Rhs.y[j], Rhs.data[j++]);

    Temp.Size = k;
    Temp.Index_Of_Data = k;

    return Temp;
}

void Sparse_Matrix::Add_Data_at(int index, int X_Temp, int Y_Temp, wchar_t *Data_Temp)
{
    x[index] = X_Temp;
    y[index] = Y_Temp;
    data[index] = new wchar_t[wcslen(Data_Temp) + 1];
    wcscpy(data[index],Data_Temp);
}
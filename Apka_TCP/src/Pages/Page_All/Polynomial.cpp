#include "Polynomial.h"

int Pollynom::To_Int_From_Wchar(wchar_t *Number)
{
    std::wstring Number_String = Number;
    return std::stoi(Number_String);
}

const wchar_t *Pollynom::To_Wchar_Form_Int(int Number)
{
    std::wstring Number_String;
    Number_String = std::to_wstring(Number);
    const wchar_t *Number_Wchar = Number_String.c_str();
    return Number_Wchar;
}

void Pollynom::Set_Number_Of_Poly(wchar_t *Edit_Box)
{
    Number_Of_Poly = To_Int_From_Wchar(Edit_Box);
}

int Pollynom::Set_Polynomial(wchar_t *Edit_Box_Coef, wchar_t *Edit_Box_Expo)
{
    if (Index_Of_Coef_Expo != Number_Of_Poly)
    {
        std::wstring Coef_Wstring = Edit_Box_Coef, Expo_Wstring = Edit_Box_Expo;
        Coef_Ecpo.Coeficient.push_back(std::stoi(Coef_Wstring));
        Coef_Ecpo.Exponecial.push_back(std::stoi(Expo_Wstring));
        Index_Of_Coef_Expo++;
        return 1;
    }
    else
        return -1;
}

const wchar_t *Pollynom::Result(wchar_t *Number)
{
    std::vector<int> Result;
    std::wstring Result_Wstring = L"";
    int Number_Int = To_Int_From_Wchar(Number);
    for (int i{}; i < Number_Of_Poly; i++)
    {
        Result.push_back(Coef_Ecpo.Coeficient.at(i) * Pow(Number_Int, Coef_Ecpo.Exponecial.at(i)));
        Result_Wstring += To_Wchar_Form_Int(Result.at(i));
        if (i != Number_Of_Poly - 1)
        {
            Result_Wstring += L" + ";
        }
    }

    return Result_Wstring.c_str();
}

int Pollynom::Pow(int Number, int Coeficient)
{
    int result{Number};
    for (int i{}; i < Coeficient; i++)
    {
        result *= Number;
    }
    return result;
}

const wchar_t *Pollynom::Print_Coef()
{
    std::wstring Coef_String;
    for (int i{}; i < Number_Of_Poly; i++)
    {
        Coef_String += std::to_wstring(Coef_Ecpo.Coeficient.at(i));
        Coef_String += L",";
    }
    return Coef_String.c_str();
}
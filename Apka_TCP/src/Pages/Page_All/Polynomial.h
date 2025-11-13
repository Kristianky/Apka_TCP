#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <vector>
#include <string>

struct Polynomial
{
    std::vector<int> Coeficient;
    std::vector<int> Exponecial;
};

class Pollynom
{
private:
    int Number_Of_Poly;
    Polynomial Coef_Ecpo;

public:
    Pollynom() = default;
    ~Pollynom() = default;
    void Set_Number_Of_Poly(wchar_t *Edit_Box);
    int Set_Polynomial(wchar_t *Edit_Box_Coef, wchar_t *Edit_Box_Expo, int index);
    int To_Int_From_Wchar(wchar_t *Number);
    const wchar_t *To_Wchar_Form_Int(int Number);
};

#endif
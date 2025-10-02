#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_



class Sparse_Matrix{
    private:
     int size,Lenght_X,Lenght_Y;
     wchar_t *data;
     int *x;
     int *y;
    public:
     void add_data();
     Sparse_Matrix(int size,int Lenght_X,int Lenght_Y)
     :size{size},Lenght_X{Lenght_X},Lenght_Y{Lenght_Y} { data = new wchar_t[size];x = new int[Lenght_X];y = new int [Lenght_Y];};
     ~Sparse_Matrix() = default;
};



#endif
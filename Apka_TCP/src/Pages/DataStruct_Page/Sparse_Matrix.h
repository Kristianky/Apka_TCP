#ifndef _SPARSE_MATRIX_H_
#define _SPARSE_MATRIX_H_

template <class t>
class Sparse_Matrix{
    private:
     int size,Lenght_X,Lenght_Y;
     t *data;
     int *x;
     int *y;
    public:
     void add_data(t data,int x,int y);
     Sparse_Matrix(int size,int Lenght_X,int Lenght_Y)
     :size = size,Lenght_X = Lenght_X,Lenght_Y = Lenght_Y { data = new t[size];x = new int[Lenght_X];y = new int [Lenght_Y];};
     ~Sparse_Matrix() = default;
};

template <class t>
void Sparse_Matrix<t>::add_data(t data,int x,int y){
    for (int i{},i < size,i++){
        if (x < Lenght_X & y < Lenght_Y)
    }

 }
#endif
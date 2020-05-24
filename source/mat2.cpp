#include "mat2.hpp"
#include <iostream>

Mat2& Mat2::operator*=(Mat2 const& m){

    Mat2 multm{*this};
    Mat2 matmat{
        (multm.e_00*m.e_00) + (multm.e_01*m.e_10),
        (multm.e_00*m.e_01) + (multm.e_01*m.e_11),
        (multm.e_10*m.e_00) + (multm.e_11*m.e_10),
        (multm.e_10*m.e_01) + (multm.e_11*m.e_11),
    };

    e_00 = matmat.e_00;
    e_01 = matmat.e_01;
    e_10 = matmat.e_10;
    e_11 = matmat.e_11;

    return *this;

    //first try -> count *= count didnt work
    /**std::cout<<e_00<<" "<<e_01<<" "<<e_10<<" "<<e_11<<std::endl;
    std::cout<<m.e_00<<" "<<m.e_01<<" "<<m.e_10<<" "<<m.e_11<<std::endl;
    Mat2 multm{*this};
    e_00 = (multm.e_00*m.e_00) + (multm.e_01*m.e_10);
    e_01 = (multm.e_00*m.e_01) + (multm.e_01*m.e_11);
    e_10 = (multm.e_10*m.e_00) + (multm.e_11*m.e_10);
    e_11 = (multm.e_10*m.e_01) + (multm.e_11*m.e_11);
    std::cout<<multm.e_00<<" "<<multm.e_01<<" "<<multm.e_10<<" "<<multm.e_11<<std::endl;
    std::cout<<e_00<<" "<<e_01<<" "<<e_10<<" "<<e_11<<std::endl;**/
  
    //didnt work either
    /**float matrix[2][2]{
        {e_00, e_01},
        {e_10, e_11}
    };
    float multm[2][2]{
        {m.e_00, m.e_01},
        {m.e_10, m.e_11}
    };
    int i, j, k;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            float result[i][j]{
                {0.0f,0.0f},
                {0.0f,0.0f}
                };
            for(k=0; k<2; k++){
                result[i][j] += matrix[i][k] * multm[k][i];
            }
        }
    }
    return *this;**/
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 mat{m1};
    mat*=m2;
    return mat;
}
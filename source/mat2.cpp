#include "mat2.hpp"
#include <iostream>

Mat2& Mat2::operator*=(Mat2 const& m){
    std::cout<<e_00<<" "<<e_01<<" "<<e_10<<" "<<e_11<<std::endl;
    std::cout<<m.e_00<<" "<<m.e_01<<" "<<m.e_10<<" "<<m.e_11<<std::endl;
    Mat2 multm{*this};
    e_00 = (multm.e_00*m.e_00) + (multm.e_01*m.e_10);
    e_01 = (multm.e_00*m.e_01) + (multm.e_01*m.e_11);
    e_10 = (multm.e_10*m.e_00) + (multm.e_11*m.e_10);
    e_11 = (multm.e_10*m.e_01) + (multm.e_11*m.e_11);
    std::cout<<multm.e_00<<" "<<multm.e_01<<" "<<multm.e_10<<" "<<multm.e_11<<std::endl;
    std::cout<<e_00<<" "<<e_01<<" "<<e_10<<" "<<e_11<<std::endl;
    return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 mat{m1};
    mat*=m2;
    return mat;
}
#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
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
}

 float Mat2::det() const{
    return (e_00*e_11)-(e_10*e_01);
    
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
    Mat2 mat{m1};
    mat*=m2;
    return mat;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v){    
    return {(m.e_00*v.x + m.e_01*v.y) , (m.e_10*v.x + m.e_11*v.y)};
}

Mat2 transpose(Mat2 const& m){
    Mat2 mt{};
    mt.e_00 = m.e_00;
    mt.e_01 = m.e_10;
    mt.e_10 = m.e_01;
    mt.e_11 = m.e_11;
    return mt;
}

Mat2 inverse(Mat2 const& m){

    if(m.det()==0){
        std::cout<<"your determinant = 0"<<std::endl;
        return m;
    }
    else{
    
    float det = 1/m.det();
    return {m.e_11*det, -m.e_01*det, -m.e_10*det, m.e_00*det};
    }
}

Mat2 make_rotation_mat2(float deg){
    if(deg == 0){
        std::cout<<"seems like you dont want to rotate your matrix"<<std::endl;
    }
    float phi = deg*M_PI/180.0f;
    return {std::cos(phi), -std::sin(phi), std::sin(phi), std::cos(phi)};
}
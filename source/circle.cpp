#include "circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle(Vec2 const& ctr, float r, Color const& clr):
    ctr_{ctr},
    r_{r},
    clr_{clr}{}

float Circle::circumfence() const{
    if(r_== 0.0f){
        std::cout<<"radius cannot be 0!"<<std::endl;
    }
    return M_PI*2*r_;
}    
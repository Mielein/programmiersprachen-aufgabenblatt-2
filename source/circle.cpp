#include "circle.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>
#include <iostream>

Circle::Circle():
    ctr_{},
    r_{},
    clr_{}{}

Circle::Circle(Vec2 const& ctr, float r):
    ctr_{ctr},
    r_{r}{} 

Circle::Circle(Vec2 const& ctr, float r, Color const& clr):
    ctr_{ctr},
    r_{r},
    clr_{clr}{}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr, float thickness):
    ctr_{ctr},
    r_{r},
    clr_{clr},
    thicc_{thickness}{}

Circle::Circle(Vec2 const& ctr, float r, Color const& clr, float thickness, bool highlight_color):
    ctr_{ctr},
    r_{r},
    clr_{clr},
    thicc_{thickness},
    highlighted_{}{}

float Circle::circumfence() const{
    if(r_== 0.0f){
        std::cout<<"radius cannot be 0!"<<std::endl;
    }
    return M_PI*2*r_;
}    

void Circle::draw(Window const& win) const{
    Color draw_color{clr_};
    float thic{thicc_};

    if(highlighted_){
        float const highlight_factor_r{1-clr_.r};
        float const highlight_factor_g{1-clr_.g};
        float const highlight_factor_b{1-clr_.b};
        Color draw_color{draw_color.r+highlight_factor_r,draw_color.g+highlight_factor_g,draw_color.b+highlight_factor_b};
        float thic{thic+10.0f};
    }
    Vec2 current_pt{0,r_};
    Mat2 rotmat = make_rotation_mat2(1);
    for(int i=0; i<360; ++i){
        current_pt = rotmat*current_pt;
        Vec2 new_point{current_pt.x+ctr_.x,current_pt.y+ctr_.y};
        
        //-1.0f to achieve thickness
        win.draw_line(new_point.x-1.0f, new_point.y-1.0f, new_point.x, new_point.y, draw_color.r,draw_color.g,draw_color.b, thic);
    }
}

void Circle::set_highlight(bool highlighted){
    highlighted_=highlighted;
}

bool Circle::is_inside(Vec2 const point) const{
    Vec2 ctr_pt{point-ctr_};
    float pt_ctr_sum = sqrt(pow(ctr_pt.x,2.0f)+pow(ctr_pt.y,2.0f));
    if(r_ < pt_ctr_sum){
        return false;
    }
    else return true;
}
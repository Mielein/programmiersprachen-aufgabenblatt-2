#include "rectangle.hpp"
#include <cmath>
#include <iostream>

Rectangle::Rectangle():
    min_{},
    max_{},
    color_{}{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max):
    min_{min},
    max_{max}{}    

Rectangle::Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
    min_{min},
    max_{max},
    color_{color}{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color, float thickness):
    min_{min},
    max_{max},
    color_{color},
    thicc_{thickness}{}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color, float thickness, bool highlighted):
    min_{min},
    max_{max},
    color_{color},
    thicc_{thickness},
    highlighted_{highlighted}{}

float Rectangle::circumfence() const{
    return (2*(max_.x -min_.x)+2*(max_.y - min_.y));
}   

void Rectangle::draw(Window const& win) const{
    Color draw_color{color_};
    if(highlighted_){
        Color draw_color{0.0f,1.0f,1.0f};
        thicc_ + 10.0f;
    }
    win.draw_line(max_.x,max_.y,max_.x,min_.y,draw_color.r,draw_color.g,draw_color.b,1.0f);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,draw_color.r,draw_color.g,draw_color.b, 1.0f);
    win.draw_line(min_.x, min_.y,min_.x,max_.y,draw_color.r,draw_color.g,draw_color.b ,1.0f);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,draw_color.r,draw_color.g,draw_color.b, 1.0f);
}

void Rectangle::draw(Window const& win, float thickness) const{
    Color draw_color{color_};
    if(highlighted_){
        Color draw_color{0.0f,1.0f,1.0f};
        thicc_ + 10.0f;
    }
    win.draw_line(max_.x,max_.y,max_.x,min_.y,draw_color.r,draw_color.g,draw_color.b,thicc_);
    win.draw_line(max_.x,min_.y,min_.x,min_.y,draw_color.r,draw_color.g,draw_color.b, thicc_);
    win.draw_line(min_.x, min_.y,min_.x,max_.y,draw_color.r,draw_color.g,draw_color.b , thicc_);
    win.draw_line(min_.x,max_.y,max_.x,max_.y,draw_color.r,draw_color.g,draw_color.b, thicc_);
}

void Rectangle::set_highlight(bool highlighted){
    highlighted_=highlighted;
}

bool Rectangle::is_inside(Vec2 point) const{
    if(point.x < min_.x || point.x > max_.x || point.y < min_.y || point.y > max_.y){
        return false;
    }
    else return true;
}
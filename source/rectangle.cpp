#include "rectangle.hpp"
#include <cmath>
#include <iostream>

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
    min_{min},
    max_{max},
    color_{color}{}

float Rectangle::circumfence() const{
    return abs((2*(max_.x -min_.x)+(2*(max_.y - min_.y))));
}   
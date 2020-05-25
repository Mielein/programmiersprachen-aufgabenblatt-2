#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{
    public:
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
    private:
        Vec2 const& min_;
        Vec2 const& max_;
}

#endif
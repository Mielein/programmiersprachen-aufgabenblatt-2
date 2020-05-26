#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{
    public:
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
        float circumfence() const;
    private:
        Vec2 const& min_{0.0f,0.0f};
        Vec2 const& max_{1.0f,1.0f};
        Color color_{};
};

#endif
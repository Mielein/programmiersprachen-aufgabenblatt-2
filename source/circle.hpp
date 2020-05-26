#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Circle{
    public:
        Circle(Vec2 const& ctr, float r, Color const& clr);
        float circumfence() const;
    private:
        Vec2 ctr_ = {1.0f,1.0f};
        float r_ = 1.0f;
        Color clr_{};
};
#endif
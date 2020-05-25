#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle{
    public:
        Circle(Vec2 const& ctr, float r, Color const& clr);

    private:
        Vec2 center_ = {1.0f,1.0f};
        float radius_ = 1.0f;
        Color color_{};
}
#endif
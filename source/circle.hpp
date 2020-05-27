#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle{

    public:

        Circle();
        Circle(Vec2 const& ctr, float r);
        Circle(Vec2 const& ctr, float r, Color const& clr);
        Circle(Vec2 const& ctr, float r, Color const& clr, float thickness);
        Circle(Vec2 const& ctr, float r, Color const& clr, float thickness, bool highlight_color);
        float circumfence() const;
        void draw(Window const& win) const;
        void draw(Window const& win, float thickness);
        void set_highlight(bool highlighted);
        bool is_inside(Vec2 const point) const;

    private:

        Vec2 ctr_{1.0f,1.0f};
        float r_ = 1.0f;
        Color clr_{};
        float thicc_{};
        bool highlighted_{false};
};
#endif
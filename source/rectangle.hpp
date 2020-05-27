#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle{
    public:
        Rectangle();
        Rectangle(Vec2 const& min, Vec2 const& max);
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& color, float thickness);
        Rectangle(Vec2 const& min, Vec2 const& max, Color const& color, float thickness, bool highlighted);
        float circumfence() const;
        void draw(Window const& win) const;
        void draw(Window const& win, float thickness) const;
        void set_highlight(bool highlighted);
        bool is_inside(Vec2 point) const;

    private:
        Vec2 const& min_{0.0f,0.0f};
        Vec2 const& max_{1.0f,1.0f};
        Color color_{};
        float thicc_{1.0f};
        bool highlighted_{false};
};

#endif
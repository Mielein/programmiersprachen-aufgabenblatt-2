#ifndef VEC2_HPP //Include-Guards: verhindern doppeltes Inkludieren
#define VEC2_HPP

struct Vec2{
 float x;
 float y;

 Vec2& operator+=(Vec2 const& v);
 Vec2& operator-=(Vec2 const& v);
 Vec2& operator*=(float s);
 Vec2& operator/=(float s);
};

#endif

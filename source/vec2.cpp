#include "vec2.hpp"


Vec2& Vec2::operator+=(Vec2 const& v){
  x+=v.x;
  y+=v.y;
  return *this;
 }
Vec2& Vec2::operator-=(Vec2 const& v){
  x-=v.x;
  y-=v.y;
  return *this;
 }

Vec2& Vec2::operator*=(float s){
  s*=x;
  s*=y;
  return *this;
 }

Vec2& Vec2::operator/=(float s){
  x/=s;
  y/=s;
  return *this;
 }

//freie Methoden
Vec2 operator+(Vec2 const& u, Vec2 const& v){
  Vec2 a{u};
  a+=v;
  return a;
}
Vec2 operator-(Vec2 const& u, Vec2 const&v){
  Vec2 s{u};
  s-=v;
  return s;  
}
Vec2 operator*(Vec2 const& v, float s){
  Vec2 m{v};
  m*=s;
  return m;
}
Vec2 operator/(Vec2 const& v, float s){
  Vec2 d{v};
  d/=s;
  return d;
}
Vec2 operator*(float s, Vec2 const v){
  Vec2 m2{v};
  m2*=s;
  return m2;
}



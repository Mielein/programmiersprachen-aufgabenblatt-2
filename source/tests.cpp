#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include <iostream>




TEST_CASE("vec2 test","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  //für Memberfunktionen Vec2
  Vec2 c{a};
  c += b;
  Vec2 d{a};
  d -= b;
  Vec2 e{b};
  e *= 1.0f;
  Vec2 f{b};
  f /= 3.0f;
  //für freie Funktionen Vec2
  Vec2 g{a+b};
  Vec2 h{a-b};
  Vec2 i{b*1.0f};
  Vec2 j{b/3.0f};
  Vec2 k{1.0f*b};
  //für Memberfunktion Mat2
  Mat2 mat0{};
  Mat2 zero{0.0f,0.0f,0.0f,0.0f};
  Mat2 mat1{1.0f,1.0f,1.0f,1.0f};
  mat1 *= mat0;
  zero *= mat1;
  Mat2 count{1.0f,2.0f,3.0f,4.0f};
  Mat2 count1{1.0f,2.0f,3.0f,4.0f};
  count *= count;
  //count *= count; //warum geht das nicht?
  //für freie Funktion Mat2
  /**Mat2 mat2{mat1*mat0};
  Mat2 mat3{zero*mat1};
  Mat2 mat4{count1*count};**/
  
  
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));

  //Test Vec2& operator+=(Vec2 const& v)
  REQUIRE(c.y == Approx(-9.3f));
  REQUIRE(c.x == Approx(5.1f));

  //Test Vec2& operator-=(Vec2 const& v)
  REQUIRE(d.x == Approx(-5.1f));
  REQUIRE(d.y == Approx(9.3f));

  //Test Vec2& operator*=(float s)
  REQUIRE(e.x == Approx(5.1f));
  REQUIRE(e.y == Approx(-9.3f));

  //Test Vec2& operator/=(float s)
  REQUIRE(f.x == Approx(1.7f));
  REQUIRE(f.y == Approx(-3.1f));

  //Test Vec2 operator+(Vec2 const& u, Vec2 const& v)
  REQUIRE(g.x == Approx(5.1f));
  REQUIRE(g.y == Approx(-9.3f));
  
  //Test Vec2 operator-(Vec2 const& u, Vec2 const&v)
  REQUIRE(h.x == Approx(-5.1f));
  REQUIRE(h.y == Approx(9.3f));

  //Test Vec2 operator*(Vec2 const& v, float s)
  REQUIRE(i.x == Approx(5.1f));
  REQUIRE(i.y == Approx(-9.3f));

  //Test Vec2 operator/(Vec2 const& v, float s)
  REQUIRE(j.x == Approx(1.7f));
  REQUIRE(j.y == Approx(-3.1f));

  //Test Vec2 operator*(float s, Vec2 const v)
  REQUIRE(k.x == Approx(5.1f));
  REQUIRE(k.y == Approx(-9.3f));

  //Test Mat2 & operator *=( Mat2 const & m )
  REQUIRE(mat1.e_00 == Approx(1.0f));
  REQUIRE(mat1.e_01 == Approx(1.0f));
  REQUIRE(mat1.e_10 == Approx(1.0f));
  REQUIRE(mat1.e_11 == Approx(1.0f));
  REQUIRE(zero.e_00 == Approx(0.0f));
  REQUIRE(zero.e_01 == Approx(0.0f));
  REQUIRE(zero.e_10 == Approx(0.0f));
  REQUIRE(zero.e_11 == Approx(0.0f));
  REQUIRE(count.e_00 == Approx(7.0f));
  REQUIRE(count.e_01 == Approx(10.0f));
  REQUIRE(count.e_10 == Approx(15.0f));
  REQUIRE(count.e_11 == Approx(22.0f));

 /** //Test Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 )
  REQUIRE(mat2.e_00 == Approx(1.0f));
  REQUIRE(mat2.e_01 == Approx(1.0f));
  REQUIRE(mat2.e_10 == Approx(1.0f));
  REQUIRE(mat2.e_11 == Approx(1.0f));
  REQUIRE(mat3.e_00 == Approx(0.0f));
  REQUIRE(mat3.e_01 == Approx(0.0f));
  REQUIRE(mat3.e_10 == Approx(0.0f));
  REQUIRE(mat3.e_11 == Approx(0.0f));
  REQUIRE(mat4.e_00 == Approx(7.0f));
  REQUIRE(mat4.e_01 == Approx(10.0f));
  REQUIRE(mat4.e_10 == Approx(15.0f));
  REQUIRE(mat4.e_11 == Approx(22.0f));**/
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

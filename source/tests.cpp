#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "window.hpp"

TEST_CASE("vec2 test","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
}

TEST_CASE("vec2 test +=","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  Vec2 const null{0.0f,0.0f};

  Vec2 c{a};
  c += b;
  Vec2 d{null};
  d += null;
 
  //Test Vec2& operator+=(Vec2 const& v)
  REQUIRE(c.y == Approx(-9.3f));
  REQUIRE(c.x == Approx(5.1f));
  REQUIRE(d.x == Approx(0.0f));
  REQUIRE(d.y == Approx(0.0f));
}

TEST_CASE("vec2 test -=","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  Vec2 const null{0.0f,0.0f};
  
  Vec2 c{a};
  c -= b;
  Vec2 d{null};
  d -= null;

  //Test Vec2& operator-=(Vec2 const& v)
  REQUIRE(c.x == Approx(-5.1f));
  REQUIRE(c.y == Approx(9.3f));
  REQUIRE(d.x == Approx(0.0f));
  REQUIRE(d.y == Approx(0.0f));
}

TEST_CASE("vec2 test *=","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  
  Vec2 c{b};
  c *= 1.0f;
  
  //Test Vec2& operator*=(float s)
  REQUIRE(c.x == Approx(5.1f));
  REQUIRE(c.y == Approx(-9.3f));
}

TEST_CASE("vec2 test /=","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
 
  Vec2 c{b};
  c /= 3.0f;

  //Test Vec2& operator/=(float s)
  REQUIRE(c.x == Approx(1.7f));
  REQUIRE(c.y == Approx(-3.1f));
}

TEST_CASE("vec2 test +","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
 
  Vec2 c{a+b};
 
  //Test Vec2 operator+(Vec2 const& u, Vec2 const& v)
  REQUIRE(c.x == Approx(5.1f));
  REQUIRE(c.y == Approx(-9.3f));
}

TEST_CASE("vec2 test -","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
 
  Vec2 c{a-b};
  
  //Test Vec2 operator-(Vec2 const& u, Vec2 const&v)
  REQUIRE(c.x == Approx(-5.1f));
  REQUIRE(c.y == Approx(9.3f));
}

TEST_CASE("vec2 test b*a","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
 
  Vec2 c{b*1.0f};
  
  //Test Vec2 operator*(Vec2 const& v, float s)
  REQUIRE(c.x == Approx(5.1f));
  REQUIRE(c.y == Approx(-9.3f));
}

TEST_CASE("vec2 test /","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
 
  Vec2 c{b/3.0f};

  //Test Vec2 operator/(Vec2 const& v, float s)
  REQUIRE(c.x == Approx(1.7f));
  REQUIRE(c.y == Approx(-3.1f));
}

TEST_CASE("vec2 test a*b","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
 
  Vec2 c{1.0f*b};

  //Test Vec2 operator*(float s, Vec2 const v)
  REQUIRE(c.x == Approx(5.1f));
  REQUIRE(c.y == Approx(-9.3f));
}

TEST_CASE("mat2 test *=","[mat2]"){
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
}

TEST_CASE("mat2 test *","[mat2]"){
  Mat2 mat0{};
  Mat2 zero{0.0f,0.0f,0.0f,0.0f};
  Mat2 mat1{1.0f,1.0f,1.0f,1.0f};
  Mat2 count{1.0f,2.0f,3.0f,4.0f};
  Mat2 count1{1.0f,2.0f,3.0f,4.0f};

  //für freie Funktion Mat2
  Mat2 mat2{mat1*mat0};
  Mat2 mat3{zero*mat1};
  Mat2 mat4{count1*count};

  //Test Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 )
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
  REQUIRE(mat4.e_11 == Approx(22.0f));
}

TEST_CASE("mat2 test det()","[mat2]"){
  Mat2 mat0{};
  Mat2 zero{0.0f,0.0f,0.0f,0.0f};
  Mat2 mat1{1.0f,1.0f,1.0f,1.0f};
  Mat2 count{1.0f,2.0f,3.0f,4.0f};
  Mat2 count1{-1.0f,-2.0f,-3.0f,-4.0f};

  REQUIRE(mat0.det()==Approx(1.0f));
  REQUIRE(zero.det()==Approx(0.0f));
  REQUIRE(mat1.det()==Approx(0.0f));
  REQUIRE(count.det()==Approx(-2.0f));
  REQUIRE(count1.det()==Approx(-2.0f));
}

TEST_CASE("mat2 test vec*mat","[mat2]"){
  Mat2 mat0{};
  Mat2 zero{0.0f,0.0f,0.0f,0.0f};
  Mat2 mat1{1.0f,1.0f,1.0f,1.0f};
  Mat2 count{1.0f,2.0f,3.0f,4.0f};
  Mat2 count1{-1.0f,-2.0f,-3.0f,-4.0f};

  Vec2 a{};
  Vec2 b{5.1f,-9.3f};
  Vec2 c{0.0f,0.0f};
  Vec2 d{5.0f,3.0f};

  a = mat0*a;
  b = mat1*b;
  c = zero*c;
  d = count*d;

  REQUIRE(a.x == Approx(0.0f));
  REQUIRE(a.y == Approx(0.0f));
  REQUIRE(b.x == Approx(-4.2f));
  REQUIRE(b.x == Approx(-4.2f));
  REQUIRE(c.x == Approx(0.0f));
  REQUIRE(c.y == Approx(0.0f));
  REQUIRE(d.x == Approx(11.0f));
  REQUIRE(d.y == Approx(27.0f));
}

TEST_CASE("mat2 test transpose"){
  Mat2 mat0{};
  Mat2 zero{0.0f,0.0f,0.0f,0.0f};
  Mat2 mat1{1.0f,1.0f,1.0f,1.0f};
  Mat2 count{1.0f,2.0f,3.0f,4.0f};
  Mat2 count1{-1.0f,-2.0f,-3.0f,-4.0f};

  Mat2 a{transpose(mat0)};
  Mat2 b{transpose(zero)};
  Mat2 c{transpose(mat1)};
  Mat2 d{transpose(count)};
  Mat2 e{transpose(count1)};

  REQUIRE(a.e_00 == Approx(1.0f));
  REQUIRE(a.e_01 == Approx(0.0f));
  REQUIRE(a.e_10 == Approx(0.0f));
  REQUIRE(a.e_11 == Approx(1.0f));
  REQUIRE(b.e_00 == Approx(0.0f));
  REQUIRE(b.e_01 == Approx(0.0f));
  REQUIRE(b.e_10 == Approx(0.0f));
  REQUIRE(b.e_11 == Approx(0.0f));
  REQUIRE(c.e_00 == Approx(1.0f));
  REQUIRE(c.e_01 == Approx(1.0f));
  REQUIRE(c.e_10 == Approx(1.0f));
  REQUIRE(c.e_11 == Approx(1.0f));
  REQUIRE(d.e_00 == Approx(1.0f));
  REQUIRE(d.e_01 == Approx(3.0f));
  REQUIRE(d.e_10 == Approx(2.0f));
  REQUIRE(d.e_11 == Approx(4.0f));
  REQUIRE(e.e_00 == Approx(-1.0f));
  REQUIRE(e.e_01 == Approx(-3.0f));
  REQUIRE(e.e_10 == Approx(-2.0f));
  REQUIRE(e.e_11 == Approx(-4.0f));
}

  TEST_CASE("mat2 test inverse","[mat2]"){
  Mat2 mat0{};
  Mat2 zero{0.0f,0.0f,0.0f,0.0f};
  Mat2 mat1{1.0f,1.0f,1.0f,1.0f};
  Mat2 count{1.0f,2.0f,3.0f,4.0f};
  Mat2 count1{-1.0f,-2.0f,-3.0f,-4.0f};

  Mat2 a = inverse(mat0);
  Mat2 b = inverse(zero);
  Mat2 c = inverse(mat1);
  Mat2 d = inverse(count);
  Mat2 e = inverse(count1);
  //a
  REQUIRE(a.e_00 == Approx(1.0f));
  REQUIRE(a.e_01 == Approx(0.0f));
  REQUIRE(a.e_10 == Approx(0.0f));
  REQUIRE(a.e_11 == Approx(1.0f));
  //b
  REQUIRE(b.e_00 == Approx(0.0f));
  REQUIRE(b.e_01 == Approx(0.0f));
  REQUIRE(b.e_10 == Approx(0.0f));
  REQUIRE(b.e_11 == Approx(0.0f));
  //c
  REQUIRE(c.e_00 == Approx(1.0f));
  REQUIRE(c.e_01 == Approx(1.0f));
  REQUIRE(c.e_10 == Approx(1.0f));
  REQUIRE(c.e_11 == Approx(1.0f));
  //d
  //REQUIRE(d.e_00 == Approx(-2.0f));
  REQUIRE(d.e_01 == Approx(1.0f));
  REQUIRE(d.e_10 == Approx(1.5f));
  REQUIRE(d.e_11 == Approx(-0.5f));
  //e
  REQUIRE(e.e_00 == Approx(2.0f));
  REQUIRE(e.e_01 == Approx(-1.0f));
  REQUIRE(e.e_10 == Approx(-1.5f));
  REQUIRE(e.e_11 == Approx(0.5f));
}

TEST_CASE("mat2 test make_rotation_mat2","[mat2]"){
  
  Mat2 mat0 ={make_rotation_mat2(90.0f)};
  Mat2 zero ={make_rotation_mat2(0.0f)};
  Mat2 mat1 ={make_rotation_mat2(1.0f)};
  Mat2 mat2 ={make_rotation_mat2(-1.0f)};

  //mat0
  REQUIRE(mat0.e_00 == Approx(0.0f));
  REQUIRE(mat0.e_01 == Approx(-1.0f));
  REQUIRE(mat0.e_10 == Approx(1.0f));
  REQUIRE(mat0.e_11 == Approx(0.0f));
  //zero
  REQUIRE(zero.e_00 == Approx(1.0f));
  REQUIRE(zero.e_01 == Approx(0.0f));
  REQUIRE(zero.e_10 == Approx(0.0f));
  REQUIRE(zero.e_11 == Approx(1.0f));
  //mat1
  REQUIRE(mat1.e_00 == Approx(0.99985f));
  REQUIRE(mat1.e_01 == Approx(-0.01745f));
  REQUIRE(mat1.e_10 == Approx(0.01745f));
  REQUIRE(mat1.e_11 == Approx(0.99985f));
  //mat2
  REQUIRE(mat2.e_00 == Approx(0.99985f));
  REQUIRE(mat2.e_01 == Approx(0.01745f));
  REQUIRE(mat2.e_10 == Approx(-0.01745f));
  REQUIRE(mat2.e_11 == Approx(0.99985f));
}

TEST_CASE("color test rgb", "[color]"){
  Color color{};
  Color zero{0.0f,0.0f,0.0f};
  Color random{0.3f,0.8f,1.0f};
  //color
  REQUIRE(color.r == Approx(0.5f));
  REQUIRE(color.g == Approx(0.5f));
  REQUIRE(color.b == Approx(0.5f));
  //zero
  REQUIRE(zero.r == Approx(0.0f));
  REQUIRE(zero.g == Approx(0.0f));
  REQUIRE(zero.b == Approx(0.0f));
  //random
  REQUIRE(random.r == Approx(0.3f));
  REQUIRE(random.g == Approx(0.8f));
  REQUIRE(random.b == Approx(1.0f));

}

TEST_CASE("Circle test circumfence","[circle]"){
  Circle c2{{1.0f,1.0f}, 2.0f, {0.5f,0.5f,0.5f}};
  Circle c1{{1.0f,1.0f}, 1.0f, {0.5f,0.5f,0.5f}};
  Circle c0{{1.0f,1.0f}, 0.0f, {0.5f,0.5f,0.5f}};

  REQUIRE(c2.circumfence() == Approx(12.56637f));
  REQUIRE(c1.circumfence() == Approx(6.28319f));
  REQUIRE(c0.circumfence() == Approx(0.0f));
}

TEST_CASE("Rectangle test circumfence","[rectangle]"){
  Rectangle rec2{{-2.0f,-3.0f},{2.0f,3.0f},{0.5f,0.5f,0.5f}};
  //Rectangle rec1{{1.0f,1.0f},{1.0f,1.0f},{0.5f,0.5f,0.5f}};
  

  REQUIRE(rec2.circumfence() == Approx(20.0f));
  //REQUIRE(rec1.circumfence() == Approx(0.0f));//what??? 
}

TEST_CASE("is_inside test circle","[circle]"){
  Circle c1{{1.0f,1.0f}, 2.0f, {0.5f,0.5f,0.5f}};
  Vec2 pt1{1.0f,1.0f};
  Vec2 pt3{0.0f,0.0f};
  bool a = c1.is_inside(pt1);
  REQUIRE(a == true);

  Circle c2{{2.0f,2.0f}, 1.0f, {0.5f,0.5f,0.5f}};
  bool b = c2.is_inside(pt1);
  REQUIRE(b == false);

  Circle c4{{0.0f,0.0f},1.0f,{}};
  bool d = c4.is_inside(pt3);
  REQUIRE(d == true);
}

TEST_CASE("is_inside test rectangle","[rectangle]"){
  Rectangle rec2{{-2.0f,-3.0f},{2.0f,3.0f},{0.5f,0.5f,0.5f}};
  Vec2 pt1{1.0f,-2.0f};
  bool a = rec2.is_inside(pt1);
  REQUIRE(a == true);

  Rectangle rec1{{1.0f,1.0f},{1.0f,1.0f},{0.5f,0.5f,0.5f}};
  Vec2 pt2{-2.0f,8.0f};
  bool b = rec1.is_inside(pt2);
  REQUIRE(b == false);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

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

  Vec2 c{a};
  c += b;
 
  //Test Vec2& operator+=(Vec2 const& v)
  REQUIRE(c.y == Approx(-9.3f));
  REQUIRE(c.x == Approx(5.1f));
}

TEST_CASE("vec2 test -=","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  
  Vec2 c{a};
  c -= b;

  //Test Vec2& operator-=(Vec2 const& v)
  REQUIRE(c.x == Approx(-5.1f));
  REQUIRE(c.y == Approx(9.3f));
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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

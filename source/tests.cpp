#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"




TEST_CASE("vec2 test","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  Vec2 c{a};
  c += b;
  Vec2 d{a};
  d-=b;
  Vec2 e{b};
  e*=1.0f;
  Vec2 f{b};
  f/=3.0f;
  
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));
  //Test Vec2& operator+=(Vec2 const& v)
  REQUIRE(c.y==-9.3f);
  REQUIRE(c.x==5.1f);
  //Test Vec2& operator-=(Vec2 const& v)
  REQUIRE(d.x==-5.1f);
  REQUIRE(d.y==9.3f);
  //Test Vec2& operator*=(float s)
  REQUIRE(e.x==5.1f);
  REQUIRE(e.y==-9.3f);
  //Test Vec2& operator/=(float s)
  REQUIRE(f.x==1.7f);
  REQUIRE(f.y==-3.1f);
  //REQUIRE(-9.3f/a.y==1);
  
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

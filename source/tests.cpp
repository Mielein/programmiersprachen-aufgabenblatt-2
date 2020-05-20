#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"




TEST_CASE("vec2 test","[vec2]"){
  Vec2 const a{};
  Vec2 const b{5.1f,-9.3f};
  //für Memberfunktionen
  Vec2 c{a};
  c += b;
  Vec2 d{a};
  d -= b;
  Vec2 e{b};
  e *= 1.0f;
  Vec2 f{b};
  f /= 3.0f;
  //für freie Funktionen
  Vec2 g{a+b};
  Vec2 h{a-b};
  Vec2 i{b*1.0f};
  Vec2 j{b/3.0f};
  Vec2 k{1.0f*b};
  
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
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

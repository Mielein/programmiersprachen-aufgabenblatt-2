#include "window.hpp"
#include "vec2.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }  



    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
  }

  Vec2 mouse{mouse_position.first, mouse_position.second};
  std::vector<Circle> circle;
  std::vector<Rectangle> rectangle;


  Rectangle rec1{{200.0f,200.0f},{400.0f,340.0f},{0.0f,0.0f,1.0f}};
  Rectangle rec2{{100.0f,250.0f},{300.0f,1900.0f},{0.0f,1.0f,0.0f}};
  Rectangle rec3{{400.0f,200.0f},{430.0f,400.0f},{1.0f,0.0f,0.0f}};
  Rectangle rec4{{200.0f,500.0f},{120.0f,300.0f},{1.0f,0.0f,1.0f}};
  Rectangle rec5{{120.0f,530.0f},{560.0f,140.0f},{0.0f,1.0f,1.0f}};
  rec1.draw(win);
  if(rec1.is_inside(mouse)){
    rec1.set_highlight(true);
  }
  rec2.draw(win);
  if(rec2.is_inside(mouse)){
    rec2.set_highlight(true);
  }
  rec3.draw(win);
  if(rec3.is_inside(mouse)){
    rec3.set_highlight(true);
  }
  rec4.draw(win);
  if(rec4.is_inside(mouse)){
    rec4.set_highlight(true);
  }
  rec5.draw(win);
  if(rec5.is_inside(mouse)){
    rec5.set_highlight(true);
  }
  
  Circle circ1{{350.0f,550.0f},150.0f,{1.0f,0.0f,0.0f},5.0f};
  Circle circ2{{100.0f,250.0f},300.0f,{0.0f,1.0f,0.0f},2.0f};
  Circle circ3{{230.0f,300.0f},200.0f,{0.0f,0.0f,1.0f},3.0f};
  Circle circ4{{100.0f,500.0f},50.0f,{1.0f,0.0f,1.0f},1.0f};
  Circle circ5{{330.0f,400.0f},100.0f,{1.0f,1.0f,1.0f},7.0f};

  circ1.draw(win);
  if(circ1.is_inside(mouse)){
    circ1.set_highlight(true);
  }
  circ2.draw(win); 
  if(circ2.is_inside(mouse)){
  circ2.set_highlight(true);
  }
  circ3.draw(win); 
  if(circ3.is_inside(mouse)){
  circ3.set_highlight(true);
  }
  circ4.draw(win);
  if(circ4.is_inside(mouse)){
  circ4.set_highlight(true);
  }
  circ5.draw(win); 
  if(circ5.is_inside(mouse)){
  circ5.set_highlight(true);
  }


  
    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);
  
    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
  
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }
  


  return 0;
}

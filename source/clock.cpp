#include <GLFW/glfw3.h>
#include "circle.hpp"
#include "rectangle.hpp"
#include "mat2.hpp"
#include "window.hpp"

#include <utility>
#include <vector>

int main(int argc, char* argv[])
{
    Circle clock{{200.0f,200.0f}, 300.0f,{1.0f,0.0f,1.0f}};

     Window win{std::make_pair(800,800)};
     clock.draw(win);

    while (!win.should_close()) {
     if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        win.close();
        }  

    Mat2 rotsec = make_rotation_mat2 (win.get_time()/60.0f);
    Mat2 rotmin = make_rotation_mat2 (win.get_time()/60.0f/60.0f);
    Mat2 rothour = make_rotation_mat2 (win.get_time()/60.0f/60.0f/60.0f);

    Vec2 second{0.0f,280.0f};
    Vec2 minute{0.0f,300.0f};
    Vec2 hour{0.0f,200.0f};

    second = rotsec*second;
    minute = rotmin*minute;
    hour = rothour*hour;

    win.draw_line(200.0f,200.0f,200.0f+second.x,200.0+second.y,1.0f,0.0f,1.0f,1.0f);
    win.draw_line(200.0f,200.0f,200.0f+minute.x,200.0+minute.y,1.0f,0.0f,1.0f,2.0f);
    win.draw_line(200.0f,200.0f,200.0f+hour.x,200.0+hour.y,1.0f,0.0f,1.0f,2.0f);


 }
}
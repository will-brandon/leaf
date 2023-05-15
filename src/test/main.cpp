/// 
/// @file       main.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       April 19, 2023
/// 
/// @brief   
/// 
/// @copyright  Copyright (c) 2023
/// 

#include <iostream>
#include "../utils/console.hpp"
#include "../window/managed/sdl/sdl.hpp"
#include "../window/managed/sdl/sdl_window.hpp"

using namespace std;
using namespace utl;
using namespace leaf;

class event_handler : virtual public window_event_handler_i
{
    virtual void closed(void) noexcept override
    {
        cout << "Closed\n";
    }

    virtual void user_requested_close(void) noexcept override
    {
        cout << "Close requested\n";
    }

    virtual void resized(const bounds2_t &bounds) noexcept override
    {
        cout << "Resized: " << bounds << '\n';
    }

    virtual void moved(const pos2_t &pos, const pos2_t &frame_pos) noexcept override
    {
        cout << "Moved: " << pos << ", " << frame_pos << '\n';
    }
};

int main(int argc, char **argv)
{
    try
    {
        sdl_window window1("Test1", 100, 100, 200, 200);
        sdl_window window2("Test2", 200, 128, 200, 200);
        sdl_window window3("Test3", 300, 156, 200, 200);
        
        window1.set_visible(true)->set_user_resizable(true)->focus();
        window2.set_visible(true)->set_user_resizable(true)->focus();
        window3.set_visible(true)->set_user_resizable(true)->focus();

        event_handler event_handler1;

        window2.close();
        window3.close();

        window1.event_manager()->subscribe(&event_handler1);
        
        while (sdl::instance.poll_events())
        {
            //cout << "Surface pos:\t" << window1.pos() << '\n';
            //cout << "Surface bounds:\t" << window1.bounds() << '\n';
            //cout << "Frame pos:\t" << window1.frame_pos() << '\n';
        }
    }
    catch (const exception &exc)
    {
        console::err(exc);
    }
}

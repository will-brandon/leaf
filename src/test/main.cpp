/// 
/// @file       main.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       April 19, 2023
/// 
/// @brief   
/// 
/// @copyright  Copyright (c) 2023
/// 

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/platform.h>
#include <stdio.h>
#include <iostream>
#include "../utils/console.hpp"
#include "../window/managed/sdl/sdl.hpp"
#include "../window/managed/sdl/sdl_window.hpp"
#include <limits>
using namespace std;
using namespace utl;
using namespace leaf;

int main(int argc, char **argv)
{
    try
    {
        sdl_window window1("Test1", 100, 100, 200, 200);
        sdl_window window2("Test2", 200, 128, 200, 200);
        sdl_window window3("Test3", 300, 156, 200, 200);
        
        window1.set_visible(true)->set_user_resizable(true);
        window2.set_visible(true)->set_user_resizable(true);
        window3.set_visible(true)->set_user_resizable(true);

        cout << numeric_limits<px_t>::max() << '\n';
        
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

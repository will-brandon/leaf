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

using namespace std;
using namespace utl;
using namespace leaf;

int main(int argc, char **argv)
{
    try
    {
        cout << "Living: " << sdl::instance.living_window_count() << "\t | Total: "
            << sdl::instance.window_count() << '\n';
        
        sdl_window window1("Test1", 0, 0, 600, 400);

        cout << "Living: " << sdl::instance.living_window_count() << "\t | Total: "
            << sdl::instance.window_count() << '\n';

        sdl_window window2("Test2", 0, 0, 600, 400);

        cout << "Living: " << sdl::instance.living_window_count() << "\t | Total: "
            << sdl::instance.window_count() << '\n';

        sdl_window window3("Test3", 0, 0, 600, 400);

        cout << "Living: " << sdl::instance.living_window_count() << "\t | Total: "
            << sdl::instance.window_count() << '\n';
        
        window1.set_visible(true)->set_user_resizable(true);
        window2.set_visible(true)->set_user_resizable(true);
        window3.set_visible(true)->set_user_resizable(true);

        while (sdl::instance.poll_events())
        {

        }
    }
    catch (const exception &exc)
    {
        console::err(exc);
    }
}

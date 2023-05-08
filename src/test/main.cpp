/**
 * @file    main.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 19, 2023
 * 
 * @brief   
 * 
 * @copyright Copyright (c) 2023
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <thread>
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
        cout << sdl::instance.living_window_count() << '\n';
        
        sdl_window window("Test1", 0, 0, 600, 400);

        cout << sdl::instance.living_window_count() << '\n';

        cout << window.uuid() << '\n';
        cout << window.sdl_version() << '\n';
        
        window.set_visible(true);
        window.set_user_resizable(true);

        native_surface_data_t native_surface_data = window.native_data();
        cout << ptr_to_str(native_surface_data.display_type) << '\n';

        while (sdl::instance.poll_events())
        {
            
        }
    }
    catch (const exception &exc)
    {
        console::err(exc);
    }
}

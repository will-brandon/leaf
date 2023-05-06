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
#include "../window/managed/sdl/sdl_window.hpp"

/* Sets constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

using namespace std;
using namespace utl;
using namespace leaf;

int main(int argc, char **argv)
{
    SDL_Init(0);

    try
    {
        sdl_window window("Test1", 0, 0, 600, 400);
        
        window.set_visible(true);
        window.set_user_resizable(true);

        native_surface_data_t native_surface_data = window.native_data();

        bgfx::PlatformData platform_data;
        platform_data.ndt = native_surface_data.display_type;
        platform_data.nwh = native_surface_data.handle;
        platform_data.context = NULL;
        platform_data.backBuffer = NULL;
        platform_data.backBufferDS = NULL;
        bgfx::setPlatformData(platform_data);
      
        bgfx::renderFrame();

        bgfx::init();

        SDL_Event e;
        bool quit = false;
        while (!quit)
        {
            bgfx::setViewRect(0, 100, 100, bgfx::BackbufferRatio::Double);
            bgfx::setViewClear(0, 0, 0x00FF00, (float)0.0, 0);
            
            bgfx::frame();

            while (SDL_PollEvent(&e))
            {
                if (e.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    window.close();
                    quit = true;
                }
            
                if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_c:
                        window.close();
                        quit = true;
                        break;
                    }

                }

                if (e.type == SDL_MOUSEBUTTONDOWN)
                {
                    //quit = true;
                }
            }

            window.poll_events();
        }

        bgfx::shutdown();
    }
    catch (const exception &exc)
    {
        console::err(exc);
    }
  
    SDL_Quit();
}

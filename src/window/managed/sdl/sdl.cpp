/**
 * @file    sdl.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 8, 2023
 * 
 * @brief   Implementation for a class that represents the Simple DirectMedia Layer (SDL) window
 *          library manager. The class creates a singleton object, i.e. only one window manager
 *          object can be created.
 *
 * @copyright Copyright (c) 2023
 */

#include <SDL2/SDL.h>
#include "sdl.hpp"

using namespace std;

namespace leaf
{
    bool sdl::poll_events(void) noexcept
    {
        // Poll all managed windows. If the number of living windows is not zero, store this in a
        // boolean flag as true indicating that there are still living windows.
        bool has_living_windows = poll_windows();

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            
        }

        // Return the flag indicating whether there are living windows.
        return has_living_windows;
    }
}

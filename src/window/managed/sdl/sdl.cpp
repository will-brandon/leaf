/// 
/// @file       sdl.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 8, 2023
/// 
/// @brief      Implementation for a class that represents the Simple DirectMedia Layer (SDL) window
///             library manager. The class creates a singleton object, i.e. only one window manager
///             object can be created.
///
/// @copyright  Copyright (c) 2023
/// 

#include <SDL2/SDL.h>
#include "sdl.hpp"

using namespace std;

namespace leaf
{
    // Initialize the SDL window manager instance.
    sdl sdl::instance;

    sdl::sdl(void)
    {
        // Initialize SDL with no flags.
        SDL_Init(0);
    }
    
    sdl::~sdl() noexcept
    {
        // Ensure that all windows are closed before deinitializing SDL.
        close_all_windows();

        // Deinitialize SDL.
        SDL_Quit();
    }

    void sdl::handle_event_on_subject_window(const SDL_Event &event) const noexcept
    {
        // Check each window to determine if it matches the ID of the event.
        for (managed_window *window : windows())
        {
            // Cast the managed window pointer to an SDL window pointer. Compare the window's ID to
            // the ID of the event. It is assumed that despite variation in SDL event types, the
            // 'windowID' field of the 'window' structure will always be populated with the correct
            // ID.
            if (((sdl_window *)window)->id() == event.window.windowID)
            {
                // Cast the managed window pointer to an SDL window pointer and instruct it to
                // handle the SDL event.
                ((sdl_window *)window)->handle_sdl_event(event);

                // Return false since it is assumed no other windows hold input focus so there is no
                // need to keep looking.
                return;
            }
        }
    }

    bool sdl::poll_events(void) noexcept
    {
        // Create an event variable to hold SDL events that occur.
        SDL_Event event;

        // Continouslt poll SDL events and read them into the event variable until they have all
        // been read.
        while (SDL_PollEvent(&event))
        {
            // Instruct the relevant currently-focussed window to handle the event.
            handle_event_on_subject_window(event);
        }

        // Poll all managed windows. If the number of living windows is not zero, store this in a
        // boolean flag as true indicating that there are still living windows.
        bool has_living_windows = poll_windows();

        // Return the flag indicating whether there are living windows.
        return has_living_windows;
    }
}

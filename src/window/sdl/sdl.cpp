/**
 * @file    sdl.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Implementstion for a class with static functionality to manage the Simple DirectMedia
 *          Layer (SDL) library.
 *
 * @copyright Copyright (c) 2023
 */

#include <SDL2/SDL.h>
#include "sdl.hpp"

using namespace std;

namespace leaf
{
    // Create a new init tracker for the SDL class.
    init_tracker sdl::f_init_tracker("SDL");

    // Initialize the set of registered windows to an empty STL set.
    set<sdl_window *> sdl::f_windows;

    bool sdl::did_init(void) noexcept
    {
        // Return whether the initialization tracker has registered an initialization.
        return f_init_tracker.did_init();
    }

    bool sdl::init(void)
    {
        // If SDL was already initialized, do nothing and return false indicating that no new
        // initialization took place.
        if (f_init_tracker.did_init())
        {
            return false;
        }

        // Attempts to initialize SDL. Throws an exception if an error occurs.
        if (SDL_Init(0))
        {
            throw runtime_error("Failed to initialize SDL. (" + string(SDL_GetError()) + ')');
        }

        // Inform the initialization tracker that SDL is now initialized.
        f_init_tracker.register_init();

        // Return true indicating that SDL was successfully initialized.
        return true;
    }

    bool sdl::deinit(void) noexcept
    {
        // If SDL was never initialized, do nothing and return false indicating that no new
        // deinitialization took place.
        if (!f_init_tracker.did_init())
        {
            return false;
        }

        // Destroy all windows that still exist.
        destroy_all_windows();

        // Deinitalizes SDL.
        SDL_Quit();

        // Inform the initialization tracker that SDL is now deinitialized.
        f_init_tracker.register_deinit();

        // Return true indicating that SDL was successfully deinitialized.
        return true;
    }

    size_t sdl::window_count(void) noexcept
    {
        // Return the size of the set of windows that have been registered.
        return f_windows.size();
    }

    sdl_window *sdl::create_window(void)
    {
        // Ensure that SDL was initialized.
        f_init_tracker.assert_init("create an SDL window");

        // Create a new window on the heap.
        sdl_window *window = new sdl_window();

        // Begin tracking the window.
        f_windows.insert(window);

        // Return the window pointer.
        return window;
    }

    sdl_window *sdl::create_window(const string &title, int x, int y, int width, int height)
    {
        // Ensure that SDL was initialized.
        f_init_tracker.assert_init("create an SDL window");

        // Create a new window on the heap.
        sdl_window *window = new sdl_window(title, x, y, width, height);

        // Begin tracking the window.
        f_windows.insert(window);

        // Return the window pointer.
        return window;
    }

    bool sdl::destroy_window(sdl_window *window)
    {
        // Ensure that SDL was initialized.
        f_init_tracker.assert_init("destroy an SDL window");

        // If the window pointer does not exist, do nothing and return false indicating that no
        // deletion took place.
        if (!window)
        {
            return false;
        }

        // Remove the window from the set of tracked windows.
        f_windows.erase(window);

        // Delete the window.
        delete window;

        // Return true indicating that the deletion succeeded.
        return true;
    }

    bool sdl::destroy_all_windows(void)
    {
        // Ensure that SDL was initialized.
        f_init_tracker.assert_init("destroy all SDL windows");
        
        // If there are no registered windows, return false indicating that there are no windows to
        // delete.
        if (!window_count())
        {
            return false;
        }

        // Loop through all registered windows and delete them.
        for (sdl_window *window : f_windows)
        {
            delete window;
        }

        // Return true indicating that at least one window was deleted.
        return true;
    }

    void sdl::poll_events(void)
    {
        // Ensure that SDL was initialized.
        f_init_tracker.assert_init("poll SDL events");

        SDL_Event event;

        
        while (SDL_PollEvent(&event))
        {
            
        }
    }
}

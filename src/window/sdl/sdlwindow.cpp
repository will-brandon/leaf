/**
 * @file    sdlwindow.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Implementation for a class that represents a graphical user interface window implemented
 *          with SDL.
 *
 * @copyright Copyright (c) 2023
 */

#include "sdlwindow.hpp"

using namespace std;

namespace leaf
{
    sdl_window::sdl_window(void)
        // Delegate to the constructor with explicit parameters.
        : sdl_window(
            "",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		    LEAF_WINDOW_DEFAULT_WIDTH, LEAF_WINDOW_DEFAULT_HEIGHT
        ) {}

    sdl_window::sdl_window(const string &title, int x, int y, int width, int height)
        : m_internal_window(NULL)
    {
        // Create an SDL window and store the pointer to it.
        m_internal_window = SDL_CreateWindow(title.c_str(), x, y, width, height, SDL_INIT_VIDEO);

        // Ensure that the pointer is not null, i.e. the window was successfully created.
        if (!m_internal_window)
        {
            throw runtime_error("Failed to create SDL window. (" + string(SDL_GetError()) + ')');
        }

        // Read the SDL version into the system information structure.
        SDL_VERSION(&m_system_info.version)
    }

    sdl_window::~sdl_window() noexcept
    {
        // Destroys the SDL window.
        SDL_DestroyWindow(m_internal_window);
    }

    void *sdl_window::native_handle(void) const noexcept
    {
        
        return NULL;
    }
}

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
    void sdl_window::init_natives(void)
    {
        // By default, both the display type pointer and window handle pointer are assumed to be
        // null.
        m_native_data = {NULL, NULL};

        // At compile time, determine which operating system is being used and appropriately
        // retrieve the native window data.
        #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD

            // If Linux or BSD is used, access the x11 structure to get the display type and window
            // handle.
            m_native_data.display_type = m_system_info.info.x11.display;
            m_native_data.handle = (void*)(uintptr_t)m_system_info.info.x11.window;

        #elif BX_PLATFORM_OSX

            // If macOS OSX is used, no display type is necessary. Access the cocoa structure to get
            // the window handle.
            m_native_data.handle = m_system_info.info.cocoa.window;

        #elif BX_PLATFORM_WINDOWS

            // If Windows is used, no display type is necessary. Access the win structure to get the
            // window handle.
            m_native_data.handle = m_system_info.info.win.window;

        #elif BX_PLATFORM_STEAMLINK

            // If Steamlink is used, access the vivante structure to get the display type and window
            // handle.
            m_native_data.display_type = m_system_info.info.vivante.display;
            m_native_data.handle = m_system_info.info.vivante.window;

        #endif

        // If the native window handle is null, the operating system is not supported. In this case,
        // throw an error.
        if (!m_native_data.handle)
        {
            throw runtime_error(
                "Failed to initialize native data for SDL window. (Operating system '"
                + native_os_name() + "' is not supported)");
        }
    }

    sdl_window::sdl_window(void)
        // Delegate to the constructor with explicit parameters.
        : sdl_window(
            "",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		    LEAF_WINDOW_DEFAULT_WIDTH, LEAF_WINDOW_DEFAULT_HEIGHT
        ) {}

    sdl_window::sdl_window(const string &title, int x, int y, int width, int height)
        : m_internal_window(NULL), m_is_alive(true), m_should_close(false)
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

        // Attempt to read driver-specific properties about the window. If the read fails, throw an
        // error.
        if (!SDL_GetWindowWMInfo(m_internal_window, &m_system_info))
        {
            throw runtime_error(
                "Failed to create SDL window (Failed to read driver-specific properties: "
                + string(SDL_GetError()) + ')');
        }

        // Initialize the window's native data.
        init_natives();
    }

    sdl_window::~sdl_window() noexcept
    {
        // Ensure that the internal window is destroyed.
        close();
    }

    bool sdl_window::should_close(void) const noexcept
    {
        // Return the flag denoting whether the window should close.
        return m_should_close;
    }

    bool sdl_window::is_alive(void) const noexcept
    {
        // Return the flag denoting whether the window is alive.
        return m_is_alive;
    }

    bool sdl_window::close(void) noexcept
    {
        // If the window has already been closed, do nothing and return false indicating that no
        // close was needed.
        if (!m_is_alive)
        {
            return false;
        }
        
        // Destroy the SDL window.
        SDL_DestroyWindow(m_internal_window);

        // Update the alive flag indicating that the window is now closed.
        m_is_alive = false;

        // Return true indicating that the window was successfully closed.
        return true;
    }

    native_window_data_t sdl_window::native_data(void) const noexcept
    {
        // Return the native data structure.
        return m_native_data;
    }
}

/**
 * @file    sdl_window.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 5, 2023
 * 
 * @brief   Implementation for a class that represents a graphical user interface window implemented
 *          with SDL. A window is immediately alive (open) upon its object's construction, however,
 *          it may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#include <bx/platform.h>
#include "sdl_window.hpp"

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

    void sdl_window::set_defaults(void) noexcept
    {
        // By default the window is not resizable by the user.
        set_user_resizable(false);
    }

    sdl_window::sdl_window(void)
        // Delegate to the constructor with explicit parameters.
        : sdl_window(
            "",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		    LEAF_SDL_WINDOW_DEFAULT_WIDTH, LEAF_SDL_WINDOW_DEFAULT_HEIGHT
        ) {}

    sdl_window::sdl_window(const string &title, int x, int y, int width, int height)
        // Upon creation, the window should not be flagged to close. It will not be resizable by the
        // user.
        : m_should_close(false), m_is_user_resizable(false)
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

        // Apply the defaut presets to the window.
        set_defaults();
    }

    sdl_window::~sdl_window() noexcept
    {
        // Ensure that the internal window is destroyed.
        destroy();
    }

    bool sdl_window::destroy(void) noexcept
    {
        // Try to update the flag indicating that the window was closed. If the window has already
        // been closed, do nothing and return false indicating that no close was needed.
        if (!flag_as_closed())
        {
            return false;
        }
        
        // Destroy the SDL window.
        SDL_DestroyWindow(m_internal_window);

        // Return true indicating that the window was successfully closed.
        return true;
    }

    px_t sdl_window::width(void) const noexcept
    {
        
    }

    px_t sdl_window::height(void) const noexcept
    {

    }

    px_t sdl_window::set_width(px_t width) noexcept
    {

    }

    px_t sdl_window::set_height(px_t height) noexcept
    {

    }

    void sdl_window::set_size(px_t width, px_t height) noexcept
    {

    }

    bool sdl_window::is_visible(void) const noexcept
    {

    }

    bool sdl_window::set_visible(bool is_visible) noexcept
    {

    }

    px_t sdl_window:: x(void) const noexcept
    {

    }

    px_t sdl_window::y(void) const noexcept
    {

    }

    px_t sdl_window::set_x(px_t x) noexcept
    {

    }

    px_t sdl_window::set_y(px_t y) noexcept
    {

    }

    void sdl_window::set_position(px_t x, px_t y) noexcept
    {

    }

    bool sdl_window::is_user_movable(void) const noexcept
    {

    }
            
    bool sdl_window::set_user_movable(bool is_user_movable) noexcept
    {

    }

    bool sdl_window::is_user_resizable(void) const noexcept
    {
        // Return the flag denoting whether the winddow is user-resizable.
        return m_is_user_resizable;
    }

    bool sdl_window::set_user_resizable(bool is_user_resizable) noexcept
    {
        // Store the previous value of the flag for returning.
        bool previous_value = is_user_resizable;

        // Use the SDL window resizable function on the internal handle and provide it with the
        // given boolean value as an SDL boolean enumeration.
        SDL_SetWindowResizable(m_internal_window, sdl_bool(is_user_resizable));

        // Set the flag to the new value.
        m_is_user_resizable = is_user_resizable;

        // Return the previous value.
        return previous_value;
    }

    string sdl_window::title(void) const noexcept
    {

    }

    string sdl_window::set_title(const string &title) const noexcept
    {

    }

    bool sdl_window::should_close(void) const noexcept
    {

    }

    bool sdl_window::poll_events(void) noexcept
    {

    }

    string sdl_window::native_os_name(void) const noexcept
    {
        // Return the platform name macro from the BX library.
        return BX_PLATFORM_NAME;
    }

    native_surface_data_t sdl_window::native_data(void) const noexcept
    {
        // Return the native data structure.
        return m_native_data;
    }
}

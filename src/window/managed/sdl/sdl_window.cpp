/// 
/// @file       sdl_window.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 5, 2023
/// 
/// @brief      Implementation for a class that represents a graphical user interface window
///             implemented with SDL. A window is immediately alive (open) upon its object's
///             construction, however, it may be closed before its object's destruction.
///
/// @copyright  Copyright (c) 2023
/// 

#include <SDL3/SDL.h>
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

        // Indicates whether the operating system is supported.
        bool supported_os = false;

        // At compile time, determine which operating system is being used and appropriately
        // retrieve the native window data.
        #if BX_PLATFORM_LINUX || BX_PLATFORM_BSD

            // If Linux or BSD is used, access the x11 structure to get the display type and window
            // handle.
            m_native_data.display_type = m_system_info.info.x11.display;
            m_native_data.handle = (void*)(uintptr_t)m_system_info.info.x11.window;

            // Mark the flag true indicating that the linux operating system is supported.
            supported_os = true;

        #elif BX_PLATFORM_OSX

            // If macOS OSX is used, no display type is necessary. Access the cocoa structure to get
            // the window handle.
            m_native_data.handle = m_system_info.info.cocoa.window;

            // Mark the flag true indicating that the OSX operating system is supported.
            supported_os = true;

        #elif BX_PLATFORM_WINDOWS

            // If Windows is used, no display type is necessary. Access the win structure to get the
            // window handle.
            m_native_data.handle = m_system_info.info.win.window;

            // Mark the flag true indicating that the Windows operating system is supported.
            supported_os = true;

        #elif BX_PLATFORM_STEAMLINK

            // If Steamlink is used, access the vivante structure to get the display type and window
            // handle.
            m_native_data.display_type = m_system_info.info.vivante.display;
            m_native_data.handle = m_system_info.info.vivante.window;

            // Mark the flag true indicating that the Steamlink operating system is supported.
            supported_os = true;

        #endif

        // Ensure that the operating system is supported.
        if (!supported_os)
        {
            throw runtime_error(
                "Failed to initialize native data for SDL window. (Operating system '"
                + native_os_name() + "' is not supported)");
        }

        // Ensure the native window handle is not null.
        if (!m_native_data.handle)
        {
            throw runtime_error(
                "Failed to initialize native data for SDL window. (Failed to obtain window handle "
                + string("for operating system '") + native_os_name() + "')");
        }
    }

    void sdl_window::set_defaults(void) noexcept
    {
        // By default the window is not resizable by the user. This cannot be set via a flag upon
        // window creation.
        set_user_resizable(false);
    }

    sdl_window::sdl_window(void)
        // Delegate to the constructor with explicit parameters.
        : sdl_window("", LEAF_SDL_WINDOW_DEFAULT_WIDTH, LEAF_SDL_WINDOW_DEFAULT_HEIGHT) {}
    
    sdl_window::sdl_window(const string &title, int width, int height)
        // Delegate to the constructor with explicit parameters.
        : sdl_window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height ) {}

    sdl_window::sdl_window(const string &title, int x, int y, int width, int height)
        // Upon creation, the window should not be flagged to close. It will not be resizable by the
        // user.
        : m_should_close(false), m_is_user_resizable(false)
    {
        // Establish some default flags for the window state upon creation. Only the video window
        // mode is needed and the window should start hidden.
        uint32_t window_flags = SDL_INIT_VIDEO | SDL_WINDOW_HIDDEN;

        // Create an SDL window using the default flags and store the pointer to it.
        m_internal_window = SDL_CreateWindow(title.c_str(), width, height, window_flags);

        // Ensure that the pointer is not null, i.e. the window was successfully created.
        if (!m_internal_window)
        {
            throw runtime_error("Failed to create SDL window. (" + string(SDL_GetError()) + ')');
        }

        // Get the SDL 4-byte internal ID.
        m_id = SDL_GetWindowID(m_internal_window);

        // Attempt to read driver-specific properties about the window. If the read fails, throw an
        // error.
        if (SDL_GetWindowWMInfo(m_internal_window, &m_system_info, SDL_SYSWM_CURRENT_VERSION))
        {
            throw runtime_error(
                "Failed to create SDL window (Failed to read driver-specific properties: "
                + string(SDL_GetError()) + ')');
        }
        
        // Set the default position.
        set_pos(x, y);

        // Initialize the window's native data.
        init_natives();

        // Apply the defaut presets to the window.
        set_defaults();
        
        // Register the window with the SDL window manager.
        sdl::instance.register_window(this);
    }

    sdl_window::~sdl_window() noexcept
    {
        // Unregister the window with the SDL window manager.
        sdl::instance.unregister_window(this);

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
        
        // Notify the event manager of a close action.
        event_manager()->closed();
        
        // Destroy the SDL window.
        SDL_DestroyWindow(m_internal_window);

        // Return true indicating that the window was successfully closed.
        return true;
    }

    bool sdl_window::should_close(void) const noexcept
    {
        // Return the flag indicating whether the window should close.
        return m_should_close;
    }

    managed_window *sdl_window::set_should_close(bool should_close) noexcept
    {
        // Set the flag to the new value.
        m_should_close = should_close;

        // Return a pointer to the window for chaining.
        return this;
    }

    bool sdl_window::poll_events(void) noexcept
    {
        // If the window is not alive return false immediately.
        if (!is_alive())
        {
            return false;
        }

        // Check if the window should close and destroy it if necessary.
        if (m_should_close)
        {
            // Destroy the window.
            destroy();

            // Return false inciating that the window is now dead.
            return false;
        }

        // Return true indicating that the window is still alive.
        return true;
    }

    uint32_t sdl_window::id(void) const noexcept
    {
        // Return the internal SDL identifier.
        return m_id;
    }

    void sdl_window::handle_sdl_event(const SDL_Event &event) noexcept
    {
        switch (event.type)
        {
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                        if (is_user_closable())
                        {
                            this->close();
                        }

                break;
        }
    }

    bounds2_t sdl_window::bounds(void) const noexcept
    {
        // Allocate variables to store the width and height.
        int width, height;

        // Use SDL fucntionality to read the width and height.
        SDL_GetWindowSizeInPixels(m_internal_window, &width, &height);

        // Return a bounding rectangle structure of the given width and height. The downcast can be
        // assumed to never truncate the dimension since it is currently safe to assume that no
        // single dimension will ever need to store a value of more than 32767 pixels (the maximum
        // value of a 16-byte integer).
        return {(px_t)width, (px_t)height};
    }

    sdl_window *sdl_window::set_width(px_t width) noexcept
    {
        // Allocate a variable to store the current height.
        int height;

        // Use SDL fucntionality to read the current height.
        SDL_GetWindowSizeInPixels(m_internal_window, NULL, &height);

        // Use SDL functionality to set the width, explicitly set the height to its previous value.
        SDL_SetWindowSize(m_internal_window, width, height);

        // Return a pointer to the window for chaining.
        return this;
    }

    sdl_window *sdl_window::set_height(px_t height) noexcept
    {
        // Allocate a variable to store the current width.
        int width;

        // Use SDL fucntionality to read the current width.
        SDL_GetWindowSizeInPixels(m_internal_window, &width, NULL);

        // Use SDL functionality to set the height, explicitly set the width to its previous value.
        SDL_SetWindowSize(m_internal_window, width, height);

        // Return a pointer to the window for chaining.
        return this;
    }

    sdl_window *sdl_window::set_size(px_t width, px_t height) noexcept
    {
        // Use SDL functionality to set the size.
        SDL_SetWindowSize(m_internal_window, width, height);

        // Return a pointer to the window for chaining.
        return this;
    }

    bool sdl_window::is_visible(void) const noexcept
    {
        // Use SDL functionality to determine if the window shown flag is enabled denoting that the
        // window is not hidden.
        return !(SDL_GetWindowFlags(m_internal_window) & SDL_WINDOW_HIDDEN);
    }

    sdl_window *sdl_window::set_visible(bool is_visible) noexcept
    {
        // If the window should be visible, show the window. Otherwise hide it.
        if (is_visible)
        {
            // Use SDL functionality to enable the shown flag.
            SDL_ShowWindow(m_internal_window);
        }
        else
        {
            // Use SDL functionality to enable the hidden flag.
            SDL_HideWindow(m_internal_window);
        }

        // Return a pointer to the window for chaining.
        return this;
    }

    pos2_t sdl_window::pos(void) const noexcept
    {
        // Allocate variables to store the x-position and y-position.
        int x, y;

        // Use SDL fucntionality to read the x-position and y-position.
        SDL_GetWindowPosition(m_internal_window, &x, &y);

        // Return a position structure of the given x-position and y-position. The downcast can be
        // assumed to never truncate the dimension since it is currently safe to assume that no
        // single dimension will ever need to store a value of more than 32767 pixels (the maximum
        // value of a 16-byte integer).
        return {(px_t)x, (px_t)y};
    }

    sdl_window *sdl_window::set_x(px_t x) noexcept
    {
        // Allocate a variable to store the current y-position.
        int y;

        // Use SDL fucntionality to read the current y-position.
        SDL_GetWindowSizeInPixels(m_internal_window, NULL, &y);

        // Use SDL functionality to set the x-position, explicitly set the y-position to its
        // previous value.
        SDL_SetWindowPosition(m_internal_window, x, y);

        // Return a pointer to the window for chaining.
        return this;
    }

    sdl_window *sdl_window::set_y(px_t y) noexcept
    {
        // Allocate a variable to store the current x-position.
        int x;

        // Use SDL fucntionality to read the current x-position.
        SDL_GetWindowSizeInPixels(m_internal_window, &x, NULL);

        // Use SDL functionality to set the y-position, explicitly set the x-position to its
        // previous value.
        SDL_SetWindowPosition(m_internal_window, x, y);

        // Return a pointer to the window for chaining.
        return this;
    }

    sdl_window *sdl_window::set_pos(px_t x, px_t y) noexcept
    {
        // Use SDL functionality to set the position.
        SDL_SetWindowPosition(m_internal_window, x, y);

        // Return a pointer to the window for chaining.
        return this;
    }

    bool sdl_window::is_user_resizable(void) const noexcept
    {
        // Return the flag denoting whether the winddow is user-resizable.
        return m_is_user_resizable;
    }

    sdl_window *sdl_window::set_user_resizable(bool is_user_resizable) noexcept
    {
        // Use SDL functionality to set whether the window is user-resizable.
        SDL_SetWindowResizable(m_internal_window, (SDL_bool)is_user_resizable);

        // Set the flag to the new value.
        m_is_user_resizable = is_user_resizable;

        // Return a pointer to the window for chaining.
        return this;
    }

    string sdl_window::title(void) const noexcept
    {
        // Use SDL functionality to retrieve the title of the window.
        return SDL_GetWindowTitle(m_internal_window);
    }

    sdl_window *sdl_window::set_title(const string &title) noexcept
    {
        // Use SDL functionality to set the window title.
        SDL_SetWindowTitle(m_internal_window, title.c_str());

        // Return a pointer to the window for chaining.
        return this;
    }

    bool sdl_window::has_focus(void) const noexcept
    {
        // Use SDL functionality to reteieve the flag indicating whether the window has input focus.
        return SDL_GetWindowFlags(m_internal_window) & SDL_WINDOW_INPUT_FOCUS;
    }

    sdl_window *sdl_window::focus(void) noexcept
    {
        // Use SDL functionaslity to give the window focus and bring it to the front in terms of
        // z-position.
        SDL_RaiseWindow(m_internal_window);

        // Return a pointer to the window for chaining.
        return this;
    }

    bool sdl_window::framed(void) const noexcept
    {
        // Use SDL functionality to determine if the window borderless flag is enabled denoting that
        // the window has a border (frame).
        return !(SDL_GetWindowFlags(m_internal_window) & SDL_WINDOW_BORDERLESS);
    }

    sdl_window *sdl_window::set_framed(bool framed) noexcept
    {
        // Use SDL functionality to set whether the window has a border (frame).
        SDL_SetWindowBordered(m_internal_window, (SDL_bool)framed);

        // Return a pointer to the window for chaining.
        return this;
    }

    border_t sdl_window::frame_border(void) const
    {
        // SDL fails to recognize the macOS X frame border size. It can be manually defined.
        #if BX_PLATFORM_OSX

            // mac OS X frames only have a bar on top that is 28 pixels tall.
            return {0, 28, 0, 0};

        #endif

        // Allocate variables to store the left, top, right, and bottom measurements.
        int left, top, right, bottom;

        // Use SDL functionality to try to read the measurements of the frame border. If the call
        // fails and the window is framed, an error must have occured, and a runtime error will be
        // thrown.
        if (
            SDL_GetWindowBordersSize(m_internal_window, &top, &left, &bottom, &right) < 0
            && framed()
        )
        {
            throw runtime_error("Failed to determine SDL window frame border size. ("
                + string(SDL_GetError()) + ')');
        }

        // Return a border structure of the given left, top, right, and bottom measurements. The
        // downcast can be assumed to never truncate the dimension since it is currently safe to
        // assume that no single dimension will ever need to store a value of more than 32767 pixels
        // (the maximum value of a 16-byte integer).
        return {(px_t)left, (px_t)top, (px_t)right, (px_t)bottom};
    }

    pos2_t sdl_window::frame_pos(void) const
    {
        // Get the position of the window's display surface.
        pos2_t surface_pos = pos();

        // Get the frame border measurements.
        border_t frame_border = this->frame_border();

        // Using the position of the surface and the frame border measurements on the left and top
        // sides of the surface, use subtraction to determine where the top left corner of the frame
        // sits on the coordinate plane.
        return {
            (px_t)(surface_pos.x - frame_border.left),
            (px_t)(surface_pos.y - frame_border.top)
        };
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

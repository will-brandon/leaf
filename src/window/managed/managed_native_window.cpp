/**
 * @file    managed_native_window.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 5, 2023
 * 
 * @brief   Implementation for an abstract class that represents a graphical user interface window
 *          that is managed by a window manager and has a native handle for the underlying operating
 *          system. A window is immediately alive (open) upon its object's construction, however, it
 *          may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#include <bx/bx.h>
#include "managed_native_window.hpp"

using namespace std;

namespace leaf
{
    managed_native_window::managed_native_window(void)
    {

    }

    void managed_native_window::init_natives(void)
    {

    }

    string managed_native_window::native_os_name(void) const noexcept
    {
        // Return the platform name macro from the BX library.
        return BX_PLATFORM_NAME;
    }

    native_surface_data_t managed_native_window::native_data(void) const noexcept
    {

    }
}


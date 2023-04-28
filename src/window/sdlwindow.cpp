/**
 * @file    sdl_window.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Implementation for a class that represents a graphical user interface window implemented
 *          with SDL.
 *
 * @copyright Copyright (c) 2023
 */

#include <bx/platform.h>
#include "sdlwindow.hpp"

using namespace std;

namespace leaf
{
    inline string sdl_window::native_os_name(void) const noexcept
    {
        return BX_PLATFORM_NAME;
    }

    void *sdl_window::native_handle(void) const noexcept
    {
        return NULL;
    }
}

/**
 * @file    sdl_window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents a graphical user interface window implemented with
 *          SDL.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_WINDOW_H_HEADER_GUARD
#define SDL_WINDOW_H_HEADER_GUARD

#include "nativewindow.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window.
     */
    class sdl_window : public native_window
    {
        public:
            /**
             * @brief   Determines the name of the operating system the window resides on.
             * 
             * @return  The name string of the operating system
             */
            inline string native_os_name(void) const noexcept override;

            /**
             * @brief   Determines the operating system native handle of the window.
             * 
             * @return  The native window handle in the form of a pointer
             */
            void *native_handle(void) const noexcept override;
    };
}

#endif

/**
 * @file    nativewindow.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 29, 2023
 * 
 * @brief   Header for defining types associated with platform-dependent native windows.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef NATIVE_WINDOW_TYPES_H_HEADER_GUARD
#define NATIVE_WINDOW_TYPES_H_HEADER_GUARD

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a set of platform-dependent data to manage a window.
     */
    typedef struct native_window_data
    {
        /**
         * @brief   The operating system native display type of the window represented as a pointer.
         */
        void *display_type;

        /**
         * @brief   The operating system native handle of the window represented as a pointer.
         */
        void *handle;

    } native_window_data_t;
}

#endif

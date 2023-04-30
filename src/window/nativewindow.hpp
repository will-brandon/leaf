/**
 * @file    nativewindow.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents an interface specification for a graphical user
 *          interface window native to the operating system it resides on.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef NATIVE_WINDOW_H_HEADER_GUARD
#define NATIVE_WINDOW_H_HEADER_GUARD

#include <string>
#include "window.hpp"
#include "nativewindowtypes.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window native
     *          to the operating system it resides on.
     */
    class native_window : public window
    {
        public:
            /**
             * @brief   Determines the name of the operating system the window resides on.
             * 
             * @return  the name string of the operating system
             */
            virtual string native_os_name(void) const noexcept = 0;

            /**
             * @brief   Returns native platform-dependent data about a window.
             * 
             * @return  a structure of native window data
             */
            virtual native_window_data_t native_data(void) const noexcept = 0;
    };
}

#endif

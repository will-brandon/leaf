/**
 * @file    nativesurfacei.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents an interface specification for a graphical user
 *          interface drawing surface native to the operating system it resides on.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef NATIVE_SURFACE_I_H_HEADER_GUARD
#define NATIVE_SURFACE_I_H_HEADER_GUARD

#include <string>
#include "surfacei.hpp"
#include "nativesurfacetypes.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface drawing surface
     *          native to the operating system it resides on.
     */
    class native_surface_i : public surface_i
    {
        public:
            /**
             * @brief   Determines the name of the operating system the window resides on.
             * 
             * @return  the name string of the operating system
             * 
             * @throw   exception if an error occrued retrieving the operating system name
             */
            virtual string native_os_name(void) const = 0;

            /**
             * @brief   Returns native platform-dependent data about a window.
             * 
             * @return  a structure of native surface data
             * 
             * @throw   exception if an error occrued retrieving the native data
             */
            virtual native_surface_data_t native_data(void) const = 0;
    };
}

#endif

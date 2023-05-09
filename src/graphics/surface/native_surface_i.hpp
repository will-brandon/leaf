/// 
/// @file       native_surface_i.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       April 28, 2023
/// 
/// @brief      Header for an abstract class that represents an interface specification for a
///             graphical user interface display surface native to the operating system it resides
///             on.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef NATIVE_SURFACE_I_H_HEADER_GUARD
#define NATIVE_SURFACE_I_H_HEADER_GUARD

#include <string>
#include "surface_i.hpp"
#include "native_surface_types.hpp"

namespace leaf
{
    /// 
    /// @brief  Represents an interface specification for a graphical user interface display surface
    ///         native to the operating system it resides on.
    /// 
    class native_surface_i : public virtual surface_i
    {
        public:
            /// 
            /// @brief   Determines the name of the operating system the surface resides on.
            /// 
            /// @return  the name string of the operating system
            /// 
            /// @throw   exception if an error occrued retrieving the operating system name
            /// 
            virtual std::string native_os_name(void) const = 0;

            /// 
            /// @brief   Returns native platform-dependent data about the surface. A null display
            ///          type pointer is acceptable on some systems. However, a null handle pointer
            ///          indicates that the operating system is not supported.
            /// 
            /// @return  a structure of native surface data
            /// 
            /// @throw   exception if an error occrued retrieving the native data
            /// 
            virtual native_surface_data_t native_data(void) const = 0;
    };
}

#endif

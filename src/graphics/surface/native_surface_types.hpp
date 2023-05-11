/// 
/// @file       native_surface_types.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       April 29, 2023
/// 
/// @brief      Header for defining types associated with platform-dependent native graphical user
///             interface display surfaces.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_NATIVE_SURFACE_TYPES_HEADER_GUARD
#define LEAF_SRC_NATIVE_SURFACE_TYPES_HEADER_GUARD

namespace leaf
{
    /// 
    /// @brief  Represents a set of platform-dependent data to manage a native graphical user
    ///         interface display surface.
    /// 
    typedef struct native_surface_data
    {
        /// 
        /// @brief  The operating system native display type of the surface represented as a
        ///         pointer.
        /// 
        void *display_type;

        /// 
        /// @brief  The operating system native handle of the surface represented as a pointer.
        /// 
        void *handle;

    } native_surface_data_t;
}

#endif

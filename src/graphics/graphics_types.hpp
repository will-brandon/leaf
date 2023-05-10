/// 
/// @file       graphics_types.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 2, 2023
/// 
/// @brief      Header for defining types associated computer graphics.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_GRAPHICS_TYPES_HEADER_GUARD
#define LEAF_SRC_GRAPHICS_TYPES_HEADER_GUARD

#include <cstdint>

namespace leaf
{
    /// 
    /// @brief  Defines a dimension measured in pixels.
    /// 
    typedef int16_t px_t;

    ///
    /// @brief  Represents a 2-dimensional bounding rectangle in integer pixel measurements.
    ///
    typedef struct bounds2
    {
        /// 
        /// @brief  Defines the width of the bounding rectangle in pixels.
        /// 
        px_t width;

        /// 
        /// @brief  Defines the height of the bounding rectangle in pixels.
        /// 
        px_t height;

        /// 
        /// @brief  Determines the dimensional aspect ratio (width/height) of the bounding
        ///         rectangle.
        /// 
        /// @return the aspect ratio of the bounds
        /// 
        double aspect_ratio(void) const noexcept
        {
            // Divide the width by the height, ensure both are doubles so the decimal places are
            // preserved.
            return (double)width / (double)height;
        }

    } bounds2_t;

    ///
    /// @brief  Represents a 2-dimensional position in integer pixel cartesian coordinates.
    ///
    typedef struct pos2
    {
        /// 
        /// @brief  Defines the x-position in pixels.
        /// 
        px_t x;

        /// 
        /// @brief  Defines the y-position in pixels.
        /// 
        px_t y;

    } pos2_t;

    ///
    /// @brief  Represents the dimensions of a border in integer pixel measurements.
    ///
    typedef struct border
    {
        /// 
        /// @brief  Defines the left measure in pixels.
        /// 
        px_t left;

        /// 
        /// @brief  Defines the top measure in pixels.
        /// 
        px_t top;

        /// 
        /// @brief  Defines the right measure in pixels.
        /// 
        px_t right;

        /// 
        /// @brief  Defines the bottom measure in pixels.
        /// 
        px_t bottom;
    
    } border_t;
}

#endif

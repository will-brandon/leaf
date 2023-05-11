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
#include "../utils/display.hpp"

namespace leaf
{
    /// 
    /// @brief  Defines a dimension measured in pixels.
    /// 
    typedef int16_t px_t;

    ///
    /// @brief  Represents a 2-dimensional bounding rectangle in integer pixel measurements.
    ///
    typedef struct bounds2 : public utl::displayable
    {
        /// 
        /// @brief  Defines the width of the bounding rectangle in pixels.
        /// 
        px_t width;

        /// 
        /// @brief  Defines the height of the bounding rectangle in pixels.
        /// 
        px_t height;

        bounds2(void) noexcept = default;

        bounds2(px_t width, px_t height) noexcept
        {
            this->width = width;
            this->height = height;
        }

        /// 
        /// @brief  Determines the dimensional aspect ratio (width/height) of the bounding
        ///         rectangle.
        /// 
        /// @return the aspect ratio of the bounds
        /// 
        inline double aspect_ratio(void) const noexcept
        {
            // Divide the width by the height, ensure both are doubles so the decimal places are
            // preserved.
            return (double)width / (double)height;
        }

        /// 
        /// @brief  Creates a display string for the bounding rectangle. The width and height are
        ///         displayed in that order.
        ///
        /// @return the display string
        /// 
        virtual std::string to_string(void) const noexcept override;

    } bounds2_t;

    ///
    /// @brief  Represents a 2-dimensional position in integer pixel cartesian coordinates.
    ///
    typedef struct pos2 : public utl::displayable
    {
        /// 
        /// @brief  Defines the x-position in pixels.
        /// 
        px_t x;

        /// 
        /// @brief  Defines the y-position in pixels.
        /// 
        px_t y;

        pos2(void) noexcept = default;

        pos2(px_t x, px_t y) noexcept
        {
            this->x = x;
            this->y = y;
        }

        /// 
        /// @brief  Creates a display string for the position. The x-position and y-position are
        ///         displayed in that order.
        ///
        /// @return the display string
        /// 
        virtual std::string to_string(void) const noexcept override;

    } pos2_t;

    ///
    /// @brief  Represents the dimensions of a border in integer pixel measurements.
    ///
    typedef struct border : public utl::displayable
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

        border(void) noexcept = default;

        border(px_t left, px_t top, px_t right, px_t bottom) noexcept
        {
            this->left = left;
            this->top = top;
            this->right = right;
            this->bottom = bottom;
        }

        /// 
        /// @brief  Creates a display string for the border. The left, right, top, and bottom
        ///         measures are displayed in that order.
        ///
        /// @return the display string
        /// 
        virtual std::string to_string(void) const noexcept override;
    
    } border_t;
}

#endif

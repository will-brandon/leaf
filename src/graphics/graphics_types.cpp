/// 
/// @file       graphics_types.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 10, 2023
/// 
/// @brief      Implementation for defining types associated computer graphics.
/// 
/// @copyright  Copyright (c) 2023
/// 

#include <sstream>
#include "graphics_types.hpp"

using namespace std;

namespace leaf
{
    bounds2::bounds2(px_t width, px_t height) noexcept
    {
        // Initialize both fields within the structure.
        this->width = width;
        this->height = height;
    }

    std::string bounds2::to_string(void) const noexcept
    {
        // Create a buffered string stream to create a display string.
        stringstream stream;

        // Create a display string of the width and height fields.
        stream << '<' << width << ',' << height << '>';

        // Return the buffer from the string stream.
        return stream.str();
    }

    pos2::pos2(px_t x, px_t y) noexcept
    {
        // Initialize both fields within the structure.
        this->x = x;
        this->y = y;
    }

    std::string pos2::to_string(void) const noexcept
    {
         // Create a buffered string stream to create a display string.
        stringstream stream;

        // Create a display string of the x-position and y-position fields.
        stream << '<' << x << ',' << y << '>';

        // Return the buffer from the string stream.
        return stream.str();
    }

    border::border(px_t left, px_t top, px_t right, px_t bottom) noexcept
    {
        // Initialize each field within the structure.
        this->left = left;
        this->top = top;
        this->right = right;
        this->bottom = bottom;
    }

    std::string border::to_string(void) const noexcept
    {
        // Create a buffered string stream to create a display string.
        stringstream stream;

        // Create a display string of the left, top, right and bottom fields.
        stream << '<' << left << ',' << top << ',' << right << ',' << bottom << '>';

        // Return the buffer from the string stream.
        return stream.str();
    }
}

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
    std::string bounds2::to_string(void) const noexcept
    {
        // Create a buffered string stream to create a display string.
        stringstream stream;

        // Create a display string of the width and height fields.
        stream << '<' << width << ',' << height << '>';

        // Return the buffer from the string stream.
        return stream.str();
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

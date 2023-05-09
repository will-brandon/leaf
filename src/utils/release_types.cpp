/// 
/// @file       release_types.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 7, 2023
/// 
/// @brief      Implementation for type definitions for software releases.
/// 
/// @copyright  Copyright (c) 2023
/// 

#include <sstream>
#include "release_types.hpp"

using namespace std;

namespace utl
{
    release_version::release_version(byte_t major, byte_t minor, byte_t patch) noexcept
    // Initialize the majpor, minor, and patch components.
        : major(major), minor(minor), patch(patch) {}

    string release_version::to_string(void) const noexcept
    {
        // Create a buffered string stream to build a display string.
        stringstream stream;

        // Insert the major, minor, and patch numbers into the stream delimitered by commas. Convert
        // the numbers to integers from unisgned bytes because the bytes would be interpreted as
        // character codes in the stream.
        stream << (int)major << '.' << (int)minor << '.' << (int)patch;

        // Return the string buffer from the stream.
        return stream.str();
    }
}

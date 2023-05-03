/**
 * @file    sdl_types.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 29, 2023
 * 
 * @brief   Implementation for type definitions for Simple DirectMedia Layer (SDL).
 *
 * @copyright Copyright (c) 2023
 */

#include <sstream>
#include "sdl_types.hpp"

using namespace std;

namespace leaf
{
    ostream &operator<<(ostream &stream, const sdl_version_t &sdl_version) noexcept
    {
        // Inject the version structure display string into the output stream, then return the
        // stream.
        return stream << sdl_version.to_string();
    }

    string sdl_version::to_string(void) const noexcept
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

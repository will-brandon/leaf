/// 
/// @file       displayable.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 6, 2023
/// 
/// @brief      Header for functionality and types to support displaying objects. Provides an
///             abstract structure that represents a displayable structure. It is displayable in the
///             sense that it has a string representation.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_UTIL_SRC_DISPLAYABLE_HEADER_GUARD
#define LEAF_UTIL_SRC_DISPLAYABLE_HEADER_GUARD

#include <ostream>
#include <sstream>

namespace utl
{
    /// 
    /// @brief  Converts an integer to a displayable string.
    /// 
    /// @param  integer an integer value to display as a string
    /// 
    /// @return the display string
    /// 
    inline std::string int_to_str(long long int integer) noexcept
    {
        // Create a bufferfed string stream to use for building a string.
        std::stringstream stream;

        // Insert the number into the string stream.
        stream << integer;

        // Return the buffer from the string stream.
        return stream.str();
    }

    /// 
    /// @brief  Converts a pointer to a displayable string. Either the hexadecimal value is printed
    ///         or 'NULL' if the value is 0x0.
    /// 
    /// @param  ptr a pointer of any type to display as a string
    /// 
    /// @return the display string
    /// 
    inline std::string ptr_to_str(void *ptr) noexcept
    {
        // Create a bufferfed string stream to use for building a string.
        std::stringstream stream;

        // If the pointer is not null, insert its value into the string stream. Otherwise, insert
        // the value 'NULL' into the string stream.
        if (ptr)
        {
            stream << ptr;
        }
        else
        {
            stream << "NULL";
        }

        // Return the buffer from the string stream.
        return stream.str();
    }

    /// 
    /// @brief  Represents a displayable structure. It is displayable in the sense that it has a
    ///         string representation.
    /// 
    typedef struct displayable
    {
        /// 
        /// @brief  Inserts a displayable structure into an output stream.
        /// 
        /// @param  stream      the output stream to insert the display string into
        /// @param  displayable the structure to be stringified and inserted into the stream
        /// 
        /// @return a reference to the output stream for chaining
        /// 
        inline friend std::ostream &operator<<(
            std::ostream &stream, const displayable &displayable) noexcept
        {
            // Convert the displayable structure to a string and insert it into the stream. Return
            // the stream for chaining.
            return stream << displayable.to_string();
        }

        /// 
        /// @brief  Converts the structure to a display string.
        /// 
        /// @return string  the display string
        /// 
        virtual std::string to_string(void) const noexcept = 0;

    } displayable_t;
}

#endif
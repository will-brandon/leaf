/**
 * @file    displayable.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Header for an abstract structure that represents a displayable structure. It is
 *          displayable in the sense that it has a string representation.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef DISPLAYABLE_H_HEADER_GUARD
#define DISPLAYABLE_H_HEADER_GUARD

#include <ostream>

using namespace std;

namespace utl
{
    /**
     * @brief   Represents a displayable structure. It is displayable in the sense that it has a
     *          string representation.
     */
    typedef struct displayable
    {
        /**
         * @brief   Inserts a displayable structure into an output stream.
         * 
         * @param   stream      the output stream to insert the display string into
         * @param   displayable the structure to be stringified and inserted into the stream
         * 
         * @return  a reference to the output stream for chaining
         */
        inline friend ostream &operator<<(
            ostream &stream, const displayable &displayable) noexcept
        {
            // Convert the displayable structure to a string and insert it into the stream. Return
            // the stream for chaining.
            return stream << displayable.to_string();
        }

        /**
         * @brief   Converts the structure to a display string.
         * 
         * @return  string  the display string
         */
        virtual string to_string(void) const noexcept = 0;

    } displayable_t;
}

#endif
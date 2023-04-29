/**
 * @file    sdl.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 29, 2023
 * 
 * @brief   Header for type definitions for Simple DirectMedia Layer (SDL).
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_TYPES_H_HEADER_GUARD
#define SDL_TYPES_H_HEADER_GUARD

#include <ostream>
#include <SDL2/SDL.h>

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a version of SDL.
     */
    typedef struct sdl_version : public SDL_version
    {
        /**
         * @brief   Inserts a display string for the SDL version structure into a given output
         *          stream.
         * 
         * @param   stream      the output stream to insert a string into
         * @param   sdl_version the version structure
         * 
         * @return  the output stream for chaining
         */
        friend ostream &operator<<(ostream &stream, const sdl_version &sdl_version) noexcept;

        /**
         * @brief   Returns a display string for the SDL version.
         * 
         * @return  the display string
         */
        string to_string(void) const noexcept;

    } sdl_version_t;
}

#endif
/**
 * @file    sdl_types.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 29, 2023
 * 
 * @brief   Header for type definitions for Simple DirectMedia Layer (SDL).
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_TYPES_H_HEADER_GUARD
#define SDL_TYPES_H_HEADER_GUARD

#include <SDL2/SDL.h>

namespace leaf
{
    /**
     * @brief   Converts a standard C++ boolean to an SDL boolean enumeration type.
     * 
     * @param   value   a standard C++ boolean
     * 
     * @return  the equivalent SDL boolean enumeration type
     */
    inline SDL_bool sdl_bool(bool value) noexcept
    {
        // Simply cast the standard C++ boolean to an SDL boolean enumeration since the numeric
        // values backing the enumeration correspond directly (SDL_TRUE = 1 and SDL_FALSE = 0).
        return (SDL_bool)value;
    }
}

#endif
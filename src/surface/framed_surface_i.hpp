/**
 * @file    framed_surface_i.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 2, 2023
 * 
 * @brief   Header for an abstract class that represents an interface specification for a graphical
 *          user interface drawing surface that resides inside of a frame.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef FRAMED_SURFACE_I_H_HEADER_GUARD
#define FRAMED_SURFACE_I_H_HEADER_GUARD

#include "pos_surface_i.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface drawing surface
     *          that resides inside of a frame.
     */
    class framed_surface_i : public pos_surface_i
    {
        public:
            /**
             * @brief   Determines whether the user can interact with the surface to reposition it.
             * 
             * @return  true if and only if the user can interact with the surface to reposition it
             */
            virtual bool is_user_movable(void) const = 0;
            
            /**
             * @brief   Sets whether the user can interact with the surface to reposition it.
             * 
             * @param   is_user_movable whether the user can interact with the surface to
             *                          reposition it
             * 
             * @return  the previous value of the user movable option prior to setting
             */
            virtual bool set_user_movable(bool is_user_movable) = 0;

            /**
             * @brief   Determines whether the user can interact with the surface to resize it.
             * 
             * @return  true if and only if the user can interact with the surface to resize it
             */
            virtual bool is_user_resizable(void) const = 0;

            /**
             * @brief   Sets whether the user can interact with the surface to resize it.
             * 
             * @param   is_user_resizable   whether the user can interact with the surface to resize
             *                              it
             * 
             * @return  the previous value of the user resizable option prior to setting
             */
            virtual bool set_user_resizable(bool is_user_resizable) = 0;
    };
}

#endif

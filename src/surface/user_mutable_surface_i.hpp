/**
 * @file    user_mutable_surface_i.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 1, 2023
 * 
 * @brief   Header for an abstract class that represents an interface specification for a
 *          user-mutable graphical user interface drawing surface. It is user-mutable in the sense
 *          that it may be repositioned or resized by user interaction such as clicking and dragging
 *          the mouse.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef USER_MUTABLE_SURFACE_I_H_HEADER_GUARD
#define USER_MUTABLE_SURFACE_I_H_HEADER_GUARD

#include "mutable_surface_i.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a user-mutable graphical user interface
     *          drawing surface. It is user-mutable in the sense that it may be repositioned
     *          or resized by user interaction such as clicking and dragging the mouse.
     */
    class user_mutable_surface_i : public mutable_surface_i
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
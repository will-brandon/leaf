/**
 * @file    pos_surface_i.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 2, 2023
 * 
 * @brief   Header for an abstract class that represents an interface specification for a positioned
 *          graphical user interface display surface. It is positioned relative to the origin in the
 *          upper left corner of the monitor it resides in.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef POS_SURFACE_I_H_HEADER_GUARD
#define POS_SURFACE_I_H_HEADER_GUARD

#include "surface_i.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a positioned graphical user interface
     *          display surface. It is positioned relative to the origin in the upper left corner of
     *          the monitor it resides in.
     */
    class pos_surface_i : public surface_i
    {
        public:
            /**
             * @brief   Determines the x-position of the surface in pixels. The coordinates are
             *          cartesian and originate from the upper left corner of the monitor that the
             *          surface primarily resides in.
             * 
             * @return  the x-position of the surface in pixels
             * 
             * @throw   exception if an error occured retrieving the x-position
             */
            virtual px_t x(void) const = 0;

            /**
             * @brief   Determines the y-position of the surface in pixels. The coordinates are
             *          cartesian and originate from the upper left corner of the monitor that the
             *          surface primarily resides in.
             * 
             * @return  the y-position of the surface in pixels
             * 
             * @throw   exception if an error occured retrieving the y-position
             */
            virtual px_t y(void) const = 0;

            /**
             * @brief   Sets the x-position of the surface in pixels. The y-position is not
             *          affected. The coordinates are cartesian and originate from the upper left
             *          corner of the monitor that the surface primarily resides in.
             * 
             * @param   x   the new x-position of the surface in pixels
             * 
             * @return  the original x-position of the surface in pixels prior to this action
             * 
             * @throw   exception if an error occured setting the x-position
             */
            virtual px_t set_x(px_t x) = 0;

            /**
             * @brief   Sets the y-position of the surface in pixels. The x-position is not
             *          affected. The coordinates are cartesian and originate from the upper left
             *          corner of the monitor that the surface primarily resides in.
             * 
             * @param   y   the new y-position of the surface in pixels
             * 
             * @return  the original y-position of the surface in pixels prior to this action
             * 
             * @throw   exception if an error occured setting the y-position
             */
            virtual px_t set_y(px_t y) = 0;

            /**
             * @brief   Sets the position of the surface in pixels. Both the x-position and
             *          y-position are affected. The coordinates are cartesian and originate from
             *          the upper left corner of the monitor that the surface primarily resides in.
             * 
             * @param   x   the new x-position of the surface in pixels
             * @param   y   the new y-position of the surface in pixels
             * 
             * @throw   exception if an error occured setting the position
             */
            virtual void set_position(px_t x, px_t y) = 0;
    };
}

#endif

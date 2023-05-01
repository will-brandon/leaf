/**
 * @file    mutablesurfacei.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 1, 2023
 * 
 * @brief   Header for a class that represents an interface specification for a mutable graphical
 *          user interface drawing surface. It is mutable in the sense that it may be repositioned,
 *          resized, or hidden and shown.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef MUTABLE_SURFACE_I_H_HEADER_GUARD
#define MUTABLE_SURFACE_I_H_HEADER_GUARD

#include "surfacei.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a mutable graphical user interface drawing
     *          surface. It is mutable in the sense that it may be repositioned, resized, or hidden
     *          and shown.
     */
    class mutable_surface_i : public surface_i
    {
        public:
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
            virtual int set_x(int x) = 0;

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
            virtual int set_y(int y) = 0;

            /**
             * @brief   Sets the position of the surface in pixels. Both the x-position and
             *          y-position are affected. The coordinates are cartesian and originate from
             *          the upper left corner of the monitor that the surface primarily resides in.
             * 
             * @param   x   the new x-position of the surface in pixels
             * @param   y  the new y-position of the surface in pixels
             * 
             * @throw   exception if an error occured setting the position
             */
            virtual void set_position(int x, int y) = 0;

            /**
             * @brief   Sets the width of the surface in pixels. The height is not affected.
             * 
             * @param   width   the new width of the surface in pixels
             * 
             * @return  the original width of the surface in pixels prior to this action
             * 
             * @throw   exception if an error occured setting the width
             */
            virtual int set_width(int width) = 0;

            /**
             * @brief   Sets the height of the surface in pixels. The width is not affected.
             * 
             * @param   height   the new height of the surface in pixels
             * 
             * @return  the original height of the surface in pixels prior to this action
             * 
             * @throw   exception if an error occured setting the height
             */
            virtual int set_height(int height) = 0;

            /**
             * @brief   Sets the size of the surface in pixels. Both the width and height are
             *          affected.
             * 
             * @param   width   the new width of the surface in pixels
             * @param   height  the new height of the surface in pixels
             * 
             * @throw   exception if an error occured setting the size
             */
            virtual void set_size(int width, int height) = 0;

            /**
             * @brief   Sets whether the surface is currently visible on the user's display. A true
             *          value will make the surface visible while a false value will hide the
             *          surface. This will only account for whether the surface is active and
             *          visible in a computational sense. For instance, in the case of windows,
             *          z-overlapping or minimization may cause the surface to appear out of view.
             *          These cases are not congruent with the functionality of this action. Be sure
             *          to check implementation details for further clarification.
             * 
             * @return  whether the surface was visible prior to this action
             * 
             * @throw   exception if an error occured setting the visibility of the surface
             */
            virtual bool set_visible(bool is_visible) = 0;
    };
}

#endif

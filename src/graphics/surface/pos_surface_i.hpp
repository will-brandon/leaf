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

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a positioned graphical user interface
     *          display surface. It is positioned relative to the origin in the upper left corner of
     *          the monitor it resides in.
     */
    class pos_surface_i : public virtual surface_i
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
             * @return  a pointer to the surface for chaining
             * 
             * @throw   exception if an error occured setting the x-position
             */
            virtual pos_surface_i *set_x(px_t x) = 0;

            /**
             * @brief   Sets the y-position of the surface in pixels. The x-position is not
             *          affected. The coordinates are cartesian and originate from the upper left
             *          corner of the monitor that the surface primarily resides in.
             * 
             * @param   y   the new y-position of the surface in pixels
             * 
             * @return  a pointer to the surface for chaining
             * 
             * @throw   exception if an error occured setting the y-position
             */
            virtual pos_surface_i *set_y(px_t y) = 0;

            /**
             * @brief   Sets the position of the surface in pixels. Both the x-position and
             *          y-position are affected. The coordinates are cartesian and originate from
             *          the upper left corner of the monitor that the surface primarily resides in.
             * 
             * @param   x   the new x-position of the surface in pixels
             * @param   y   the new y-position of the surface in pixels
             * 
             * @return  a pointer to the surface for chaining
             * 
             * @throw   exception if an error occured setting the position
             */
            virtual pos_surface_i *set_position(px_t x, px_t y) = 0;

            /**
             * @brief   Moves the surface horizontally by the given displacement in pixels. Only the
             *          x-position is affected. Positive displacement values move the surface right,
             *          negative values move the surface left.
             * 
             * @param   x_displacement  the number of pixels by which to increment (or decrement)
             *                          the x-position
             * 
             * @return  a pointer to the surface for chaining
             * 
             * @throw   exception if an error occured moving the surface
             * 
             * @note    A default implementation is provided in this interface.
             */
            virtual pos_surface_i *move_horizontally(px_t x_displacement)
            {
                // Increment (or decrement) the x-position by the given distance.
                set_x(x() + x_displacement);

                // Return a pointer to the surface for chaining.
                return this;
            }

            /**
             * @brief   Moves the surface vertically by the given displacement in pixels. Only the
             *          y-position is affected. Positive displacement values move the surface down,
             *          negative values move the surface up.
             * 
             * @param   y_displacement  the number of pixels by which to increment (or decrement)
             *                          the y-position
             * 
             * @return  a pointer to the surface for chaining
             * 
             * @throw   exception if an error occured moving the surface
             * 
             * @note    A default implementation is provided in this interface.
             */
            virtual pos_surface_i *move_vertically(px_t y_displacement)
            {
                // Increment (or decrement) the y-position by the given distance.
                set_y(y() + y_displacement);

                // Return a pointer to the surface for chaining.
                return this;
            }

            /**
             * @brief   Moves the surface by the given displacement in pixels. Both the x-position
             *          and y-position are affected. For horizontal and vertical translation,
             *          positive displacement values move the surface right and down respectively,
             *          negative values move the surface left up respectively.
             * 
             * @param   x_displacement  the number of pixels by which to increment (or decrement)
             *                          the x-position
             * @param   y_displacement  the number of pixels by which to increment (or decrement)
             *                          the y-position
             * 
             * @return  a pointer to the surface for chaining
             * 
             * @throw   exception if an error occured moving the surface
             * 
             * @note    A default implementation is provided in this interface.
             */
            virtual pos_surface_i *move(px_t x_displacement, px_t y_displacement)
            {
                // Increment (or decrement) the x-position and y-position by the given distances.
                set_position(x() + x_displacement, y() + y_displacement);

                // Return a pointer to the surface for chaining.
                return this;
            }
    };
}

#endif

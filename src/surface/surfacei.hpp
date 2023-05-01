/**
 * @file    surfacei.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 1, 2023
 * 
 * @brief   Header for a class that represents an interface specification for a graphical user
 *          interface drawing surface.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef SURFACE_I_H_HEADER_GUARD
#define SURFACE_I_H_HEADER_GUARD

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface drawing
     *          surface.
     */
    class surface_i
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
            virtual int x(void) const = 0;

            /**
             * @brief   Determines the y-position of the surface in pixels. The coordinates are
             *          cartesian and originate from the upper left corner of the monitor that the
             *          surface primarily resides in.
             * 
             * @return  the y-position of the surface in pixels
             * 
             * @throw   exception if an error occured retrieving the y-position
             */
            virtual int y(void) const = 0;

            /**
             * @brief   Determines the width of the surface in pixels.
             * 
             * @return  the width of the surface in pixels
             * 
             * @throw   exception if an error occured retrieving the width
             */
            virtual int width(void) const = 0;

            /**
             * @brief   Determines the height of the surface in pixels.
             * 
             * @return  the height of the surface in pixels
             * 
             * @throw   exception if an error occured retrieving the height
             */
            virtual int height(void) const = 0;

            /**
             * @brief   Determines the dimensional aspect ratio (width/height) of the surface.
             * 
             * @return  the aspect ratio of the surface
             * 
             * @throw   exception if an error occured retrieving the aspect ratio
             */
            virtual double aspect_ratio(void) const = 0;

            /**
             * @brief   Determines whether the surface is currently visible on the user's display.
             *          This will only account for whether the surface is active and visible in a
             *          computational sense. For instance, in the case of windows, z-overlapping or
             *          minimization may cause the surface to appear out of view. These cases will
             *          not be considered hidden. Be sure to check implementation details for
             *          further clarification.
             * 
             * @return  whether the surface is currently visible
             * 
             * @throw   exception if an error occured determining whether the surface is currently
             *          visible
             */
            virtual bool is_visible(void) const = 0;
    };
}

#endif

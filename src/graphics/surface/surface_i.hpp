/// 
/// @file       surface_i.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 1, 2023
/// 
/// @brief      Header for an abstract class that represents an interface specification for a
///             graphical user interface display surface.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_SURFACE_I_HEADER_GUARD
#define LEAF_SRC_SURFACE_I_HEADER_GUARD

#include "../graphics_types.hpp"

namespace leaf
{
    /// 
    /// @brief  Represents an interface specification for a graphical user interface display
    ///         surface.
    /// 
    class surface_i
    {
        public:
            /// 
            /// @brief  Determines the width of the surface in pixels.
            /// 
            /// @return the width of the surface in pixels
            /// 
            /// @throw  exception if an error occured retrieving the width
            /// 
            virtual px_t width(void) const = 0;

            /// 
            /// @brief  Determines the height of the surface in pixels.
            /// 
            /// @return the height of the surface in pixels
            /// 
            /// @throw  exception if an error occured retrieving the height
            /// 
            virtual px_t height(void) const = 0;

            /// 
            /// @brief  Sets the width of the surface in pixels. The height is not affected.
            /// 
            /// @param  width   the new width of the surface in pixels
            /// 
            /// @return a pointer to the surface for chaining
            /// 
            /// @throw  exception if an error occured setting the width
            /// 
            virtual surface_i *set_width(px_t width) = 0;

            /// 
            /// @brief  Sets the height of the surface in pixels. The width is not affected.
            /// 
            /// @param  height  the new height of the surface in pixels
            /// 
            /// @return a pointer to the surface for chaining
            /// 
            /// @throw  exception if an error occured setting the height
            /// 
            virtual surface_i *set_height(px_t height) = 0;

            /// 
            /// @brief  Sets the size of the surface in pixels. Both the width and height are
            ///         affected.
            /// 
            /// @param  width   the new width of the surface in pixels
            /// @param  height  the new height of the surface in pixels
            /// 
            /// @return a pointer to the surface for chaining
            /// 
            /// @throw  exception if an error occured setting the size
            /// 
            virtual surface_i *set_size(px_t width, px_t height) = 0;

            /// 
            /// @brief  Determines the dimensional aspect ratio (width/height) of the surface.
            /// 
            /// @return the aspect ratio of the surface
            /// 
            /// @throw  exception if an error occured retrieving the aspect ratio
            /// 
            /// @note   A default implementation is provided in this interface.
            /// 
            virtual double aspect_ratio(void) const
            {
                // Divide the with of the surface by the height of the surface.
                return (double)width() / (double)height();
            }

            /// 
            /// @brief  Determines whether the surface is currently visible on the user's display.
            ///         This will only account for whether the surface is visible in an absolute
            ///         sense. For instance, in the case of windows, z-overlapping or minimization
            ///         may cause the surface to appear out of view. These cases will not be
            ///         considered hidden. Be sure to check implementation details for
            ///         further clarification.
            /// 
            /// @return whether the surface is currently visible
            /// 
            /// @throw  exception if an error occured determining whether the surface is currently
            ///         visible
            /// 
            virtual bool is_visible(void) const = 0;

            /// 
            /// @brief  Sets whether the surface is currently visible on the user's display. A true
            ///         value will make the surface visible while a false value will hide the
            ///         surface. This will only account for whether the surface is visible in an
            ///         absolute sense. For instance, in the case of windows, z-overlapping or
            ///         minimization may cause the surface to appear out of view. These cases are
            ///         not congruent with the functionality of this action.
            /// 
            /// @return a pointer to the surface for chaining
            /// 
            /// @throw  exception if an error occured setting the visibility of the surface
            /// 
            virtual surface_i *set_visible(bool is_visible) = 0;
    };
}

#endif

/// 
/// @file       window_event_handler_i.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 8, 2023
/// 
/// @brief      Header for an abstract class that represents an interface specification for a window
///             event handler. A window event handler will contain functionality that will be
///             triggered by a window when the handler object is subscribed to the window.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_WINDOW_EVENT_HANDLER_I_HEADER_GUARD
#define LEAF_SRC_WINDOW_EVENT_HANDLER_I_HEADER_GUARD

#include "event_handler_i.hpp"
#include "../graphics/graphics_types.hpp"

namespace leaf
{
    /// 
    /// @brief  Represents an interface specification for a window event handler. A window event
    ///         handler will contain functionality that will be triggered by a window when the
    ///         handler object is subscribed to the window.
    /// 
    class window_event_handler_i : virtual public event_handler_i
    {
        /// 
        /// @brief  Called when the window is closed either by the user or automatically.
        /// 
        /// @param  user_initiated      true if and only if the close was initated by the user as
        ///                             opposed to being automatic
        /// @param  new_width           the new width of the window's display surface
        /// @param  new_height          the new height of the window's display surface
        /// @param  new_frame_width     the new width of the window's frame
        /// @param  new_frame_height    the new height of the window's frame
        /// 
        virtual void closed(bool user_initiated) noexcept;

        /// 
        /// @brief  Called when the window is resized either by the user or automatically.
        /// 
        /// @param  user_initiated      true if and only if the resize was initated by the user as
        ///                             opposed to being automatic
        /// @param  new_width           the new width of the window's display surface
        /// @param  new_height          the new height of the window's display surface
        /// @param  new_frame_width     the new width of the window's frame
        /// @param  new_frame_height    the new height of the window's frame
        /// 
        virtual void resized(
            bool user_initiated,
            px_t new_width, px_t new_height, px_t new_frame_width, px_t new_frame_height
        ) noexcept = 0;

        /// 
        /// @brief  Called when the window is moved either by the user or automatically.
        /// 
        /// @param  user_initiated  true if and only if the move was initated by the user as opposed
        ///                         to being automatic
        /// @param  new_x       the new x-position in pixels of the window's display surface
        /// @param  new_y       the new x-position in pixels of the window's display surface
        /// @param  new_frame_x the new x-position in pixels of the window's frame
        /// @param  new_frame_y the new y-position in pixels of the window's frame
        /// 
        virtual void moved(
            bool user_initiated, px_t new_x, px_t new_y, px_t new_frame_x, px_t new_frame_y
        ) noexcept = 0;

        virtual void hidden(void) noexcept;

        virtual void shown(void) noexcept;

        virtual void minimized(void) noexcept;

        virtual void maximized(void) noexcept;

        virtual void entered_fullscreen(void) noexcept;

        virtual void exited_fullscreen(void) noexcept;
    };
}

#endif

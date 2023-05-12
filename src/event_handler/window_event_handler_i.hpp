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
        public:
            /// 
            /// @brief  Called when the window is closed either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the close was initated by the user as
            ///                         opposed to being automatic
            /// 
            virtual void closed(bool user_initiated) noexcept = 0;

            /// 
            /// @brief  Called when the window is resized either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the resize was initated by the user as
            ///                         opposed to being automatic
            /// @param  new_bounds      a bounding rectangle defining the new width and height of
            ///                         the resized window display surface
            /// 
            virtual void resized(bool user_initiated, const bounds2_t &new_bounds) noexcept = 0;

            /// 
            /// @brief  Called when the window is moved either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the move was initated by the user as
            ///                         opposed to being automatic
            /// @param  new_pos         a position defining the new x-position and y-position in
            ///                         pixels of the window's display surface after the move
            /// @param  new_frame_pos   a position defining the new x-position and y-position in
            ///                         pixels of the window's frame after the move
            /// 
            virtual void moved(
                bool user_initiated, const pos2_t &new_pos, const pos2_t &new_frame_pos
            ) noexcept = 0;
            
            /// 
            /// @brief  Called when the window is hidden either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the hide was initated by the user as
            ///                         opposed to being automatic
            /// 
            virtual void hidden(bool user_initiated) noexcept = 0;

            /// 
            /// @brief  Called when the window is shown either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the show was initated by the user as
            ///                         opposed to being automatic
            /// 
            virtual void shown(bool user_initiated) noexcept = 0;

            /// 
            /// @brief  Called when the window is minimized either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the minimization was initated by the
            ///                         user as opposed to being automatic
            /// 
            virtual void minimized(bool user_initiated) noexcept = 0;
            
            /// 
            /// @brief  Called when the window is maximized either by the user or automatically.
            /// 
            /// @param  user_initiated  true if and only if the maximization was initated by the
            ///                         user as opposed to being automatic
            /// 
            virtual void maximized(bool user_initiated) noexcept = 0;

            /// 
            /// @brief  Called when the window enters fullscreen mode either by the user or
            ///         automatically.
            /// 
            /// @param  user_initiated  true if and only if the fullscreen was initated by the user
            ///                         as opposed to being automatic
            /// 
            virtual void entered_fullscreen(bool user_initiated) noexcept = 0;

            /// 
            /// @brief  Called when the window exits fullscreen mode either by the user or
            ///         automatically.
            /// 
            /// @param  user_initiated  true if and only if the fullscreen exit was initated by the
            ///                         user as opposed to being automatic
            /// 
            virtual void exited_fullscreen(bool user_initiated) noexcept = 0;
    };
}

#endif

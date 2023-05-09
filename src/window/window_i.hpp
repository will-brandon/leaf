///
/// @file       window_i.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       April 28, 2023
///
/// @brief      Header for an abstract class that represents an interface specification for a
///             graphical user interface window. A window is immediately alive (open) upon its
///             object's construction, however, it may be closed before its object's destruction.
///
/// @copyright  Copyright (c) 2023
///

#ifndef LEAF_SRC_WINDOW_I_HEADER_GUARD
#define LEAF_SRC_WINDOW_I_HEADER_GUARD

#include <string>
#include "../graphics/surface/pos_surface_i.hpp"

namespace leaf
{
    ///
    /// @brief  Represents an interface specification for a graphical user interface window. A
    ///         window is immediately alive (open) upon its object's construction, however, it may
    ///         be closed before its object's destruction.
    ///
    class window_i : public virtual pos_surface_i
    {
        public:
            /// 
            /// @brief  Determines whether the window is alive (as opposed to being closed).
            /// 
            /// @return true if and only if the window is not closed
            /// 
            /// @throw  exception if an error occurs determining whether the window is alive
            /// 
            virtual bool is_alive(void) const = 0;
            
            /// 
            /// @brief  Informs the window that it should close. Note that this does not guaruntee
            ///         an immediate close. Depending on implementation, this may necessitate other
            ///         events to perform a close. For instance, some implementations will require
            ///         window library events to be polled to recognize that a close should take
            ///         place.
            /// 
            /// @return true if and only if the window was not already closed (or flagged to close)
            /// 
            /// @throw  exception if an error occurs closing the window (or indicating that a close
            ///         must occur)
            /// 
            virtual bool close(void) = 0;

            /// 
            /// @brief  Determines whether the window will automatically enable the close flag when
            ///         the user performs a close action on the user interface (This is often in the
            ///         form of clicking a red 'x' button on the frame).
            /// 
            /// @return true if and only if the window will automatically enable the close flag when
            ///         the user performs a close action
            /// 
            /// @throw  exception if an error occurs determining whether the window will
            ///         automatically enable the close flag
            /// 
            virtual bool is_user_closable(void) const = 0;

            /// 
            /// @brief  Sets whether the window will automatically enable the close flag when the
            ///         user performs a close action on the user interface (This is often in the
            ///         form of clicking a red 'x' button on the frame).
            /// 
            /// @param  is_user_closable    a true value indicates that the window should
            ///                             automatically enable the close flag
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs setting whether the window will automatically
            ///         enable the close flag
            /// 
            virtual window_i *set_user_closable(bool is_user_closable) = 0;
            
            /// @brief  Determines whether the user can interact with the window's frame to resize
            ///         it.
            ///
            /// @return true if and only if the user can interact with the window's frame to resize
            ///         it
            ///
            /// @throw  exception if an error occured determining whether the window is user
            ///         resizable
            ///
            virtual bool is_user_resizable(void) const = 0;

            /// 
            /// @brief  Sets whether the user can interact with the window's frame to resize it.
            /// 
            /// @param  is_user_resizable   whether the user can interact with the window's frame to
            ///                             resize it
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting whether the window is user resizable
            /// 
            virtual window_i *set_user_resizable(bool is_user_resizable) = 0;

            /// 
            /// @brief  Determines the title of the window. This title is often displayed on the
            ///         window's frame.
            /// 
            /// @return the title of the window
            /// 
            /// @throw  exception if an error occurs determining the title of the window
            /// 
            virtual std::string title(void) const = 0;

            /// 
            /// @brief  Sets the title of the window. This title is often displayed on the window's
            ///         frame.
            /// 
            /// @param  title   the title of the window
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs setting the title
            /// 
            virtual window_i *set_title(const std::string &title) = 0;
            
            /// 
            /// @brief  Determines whether the window has input focus. This also generally means
            ///         that it in the front in terms of z-position, but this is
            ///         implementation-dependent.
            /// 
            /// @return true if and only if the window has input focus
            /// 
            /// @throw  exception if an error occurs determining whether the window has input focus
            /// 
            virtual bool has_focus(void) const = 0;

            /// 
            /// @brief  Gives the window input focus if it did not have it previously. This also
            ///         generally means that it will be brought to the front in terms of z-position,
            ///         but this is implementation-dependent.
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs giving the window input focus
            /// 
            virtual window_i *focus(void) = 0;
    };
}

#endif

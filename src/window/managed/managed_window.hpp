/// 
/// @file       managed_window.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 4, 2023
///     
/// @brief      Header for an abstract class that represents a graphical user interface window that
///             is managed by a window manager. A window is immediately alive (open) upon its
///             object's construction, however, it may be closed before its object's destruction.
/// 
/// @copyright  Copyright (c) 2023
///

#ifndef LEAF_SRC_MANAGED_WINDOW_HEADER_GUARD
#define LEAF_SRC_MANAGED_WINDOW_HEADER_GUARD

// The class must be forward declared because there are circular includes between the window manager
// and managed window classes.
namespace leaf
{
    class managed_window;
}

#include "../../utils/unique.hpp"
#include "../../graphics/surface/native_surface_i.hpp"
#include "../nonatomic_window_i.hpp"
#include "window_manager.hpp"

namespace leaf
{
    /// 
    /// @brief  Represents a graphical user interface window that is managed by a window manager. A
    ///         window is immediately alive (open) upon its object's construction, however, it may
    ///         be closed before its object's destruction.
    ///
    class managed_window : public utl::unique, public virtual nonatomic_window_i
    {
        // The window manager must be able to access hidden functionality of a managed window.
        friend class window_manager;

        private:
            /// 
            /// @brief  Denotes whether the window is alive (open) or dead (closed) represented by
            ///         the values true or false respectively.
            ///
            bool m_is_alive;

            /// 
            /// @brief  Denotes whether the window can be closed by the user.
            ///
            bool m_is_user_closable;

        protected:
            /// 
            /// @brief  Creates a managed window. The title, position, and size are set to default
            ///         values. When the window is created it is immediately alive. Assuming that it
            ///         is visible and window manager events are polled, it will begin displaying
            ///         upon creation.
            ///
            managed_window(void) noexcept;

            /// 
            /// @brief  Destructs the window object.
            /// 
            /// @note   The default implementation in maintained because no resources need
            ///         deallocation. The declaration is only explicit so that the destructor can be
            ///         marked virtual.
            ///
            virtual ~managed_window() noexcept = default;

            /// 
            /// @brief  Destroys the window (deallocates internal functionality and deems it dead
            ///         and therefore closed). If the window was already closed, nothing happens.
            /// 
            /// @return true if and only if the window was not already dead (closed)
            /// 
            /// @throw  exception if an error occurs destroying the window
            ///
            virtual bool destroy(void) override = 0;

            /// 
            /// @brief  Flags the window as dead (closed). This should be used internally after the
            ///         window has been destroyed.
            /// 
            /// @return true if and only if the window was not already flagged as closed
            ///
            inline bool flag_as_closed(void) noexcept
            {
                // If the window is already closed, return false.
                if (!m_is_alive)
                {
                    return false;
                }

                // Set the flag to true indicating that the window is closed.
                m_is_alive = true;

                // Return true indicating that the flag was set successfully.
                return true;
            }

            /// 
            /// @brief  Determines whether the window should close the next time events are polled.
            /// 
            /// @return true if the window should close
            /// 
            /// @throw  exception if an error occurs determining whether the window should close
            ///
            virtual bool should_close(void) const override = 0;

            /// 
            /// @brief  Sets the flag indicating whether the window should close the next time
            ///         events are polled.
            /// 
            /// @param  should_close    true if the window should close, false if it should not
            ///                         close
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs setting whether the window should close
            ///
            virtual managed_window *set_should_close(bool should_close) override = 0;

            /// 
            /// @brief  Performs any necessary updates for the window. This includes closing the
            ///         window if a close was requested. If the window is closed, nothing happens.
            /// 
            /// @return true if and only if the window is active (has not been closed), if this
            ///         action causes the window to close or it was already closed, false will be
            ///         returned
            /// 
            /// @throw  exception if an error occurs polling window events
            ///
            virtual bool poll_events(void) override = 0;

        public:
            /// 
            /// @brief  Determines the bounds of the window's display surface in pixel measurements.
            ///         Note that the surface is only the inner content area of the window, not the
            ///         frame.
            /// 
            /// @return the bounds of the window's display surface
            /// 
            /// @throw  exception if an error occured retrieving the bounds
            /// 
            virtual bounds2_t bounds(void) const override = 0;

            /// 
            /// @brief  Sets the width of the window's display surface in pixels. The height is not
            ///         affected. Note that the surface is only the inner content area of the
            ///         window, not the frame. The frame will be resized appropriately to accomodate
            ///         the change.
            /// 
            /// @param  width   the new width of the surface in pixels
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the width
            ///
            virtual managed_window *set_width(px_t width) override = 0;

            ///
            /// @brief  Sets the height of the window's display surface in pixels. The width is not
            ///         affected. Note that the surface is only the inner content area of the
            ///         window, not the frame. The frame will be resized appropriately to accomodate
            ///         the change. 
            /// 
            /// @param  height  the new height of the surface in pixels
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the height
            ///
            virtual managed_window *set_height(px_t height) override = 0;

            /// 
            /// @brief  Sets the size of the surface in pixels. Both the width and height are
            ///         affected. Note that the surface is only the inner content area of the
            ///         window, not the frame. The frame will be resized appropriately to accomodate
            ///         the change. 
            /// 
            /// @param  width   the new width of the surface in pixels
            /// @param  height  the new height of the surface in pixels
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the size
            ///
            virtual managed_window *set_size(px_t width, px_t height) override = 0;

            /// 
            /// @brief  Determines whether the window is currently visible on the user's display.
            ///         This will only account for whether the window visible in an absolute sense.
            ///         Z-overlapping or minimization may cause the surface to appear out of view.
            ///         These cases will not be considered hidden.
            /// 
            /// @return whether the window is currently visible
            /// 
            /// @throw  exception if an error occured determining whether the window is currently
            ///         visible
            ///
            virtual bool is_visible(void) const override = 0;

            /// 
            /// @brief  Sets whether the window is currently visible on the user's display. A true
            ///         value will make the window visible while a false value will hide the window.
            ///         This will hide or show the window in an absolute sense. Z-overlapping or
            ///         minimization may cause the window to appear out of view. These cases are not
            ///         congruent with the functionality of this action.
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the visibility of the window
            ///
            virtual managed_window *set_visible(bool is_visible) override = 0;

            /// 
            /// @brief  Determines the position of the top left corner of the window's display
            ///         surface. Coordinates are cartesian and originate from the top left corner of
            ///         the monitor the window resides in.
            /// 
            /// @return the position of the window's display surface
            /// 
            /// @throw  exception if an error occured retrieving the position
            /// 
            virtual pos2_t pos(void) const override = 0;

            /// 
            /// @brief  Sets the x-position of the window's display surface in pixels. The
            ///         y-position is not affected. The coordinates are cartesian and originate from
            ///         the upper left corner of the monitor that the window primarily resides in.
            ///         Note that the surface is only the inner content area of the window, not the
            ///         frame. The frame will be repositioned appropriately to accomodate the
            ///         change. 
            /// 
            /// @param  x   the new x-position of the surface in pixels
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the x-position
            ///
            virtual managed_window *set_x(px_t x) noexcept override = 0;

            /// 
            /// @brief  Sets the y-position of the window's display surface in pixels. The
            ///         x-position is not affected. The coordinates are cartesian and originate from
            ///         the upper left corner of the monitor that the window primarily resides in.
            ///         Note that the surface is only the inner content area of the window, not the
            ///         frame. The frame will be repositioned appropriately to accomodate the
            ///         change. 
            /// 
            /// @param  y   the new y-position of the surface in pixels
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the y-position
            ///
            virtual managed_window *set_y(px_t y) override = 0;

            /// 
            /// @brief  Sets the position of the window's display surface in pixels. Both the
            ///         x-position and y-position are affected. The coordinates are cartesian and
            ///         originate from the upper left corner of the monitor that the window 
            ///         primarily resides in. Note that the surface is only the inner content area
            ///         of the window, not the frame. The frame will be repositioned appropriately
            ///         to accomodate the change. 
            /// 
            /// @param  x   the new x-position of the surface in pixels
            /// @param  y   the new y-position of the surface in pixels
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting the position
            ///
            virtual managed_window *set_pos(px_t x, px_t y) override = 0;

            /// 
            /// @brief  Determines whether the window is alive (as opposed to being closed).
            /// 
            /// @return true if and only if the window is not closed
            ///
            virtual bool is_alive(void) const noexcept override;

            /// 
            /// @brief  Informs the window that it should close. Note that this does not guaruntee
            ///         an immediate close. Window manager events must be polled to recognize that a
            ///         close should take place.
            /// 
            /// @return true if and only if the window was not already closed (or flagged to close)
            ///
            virtual bool close(void)  noexcept override;

            /// 
            /// @brief  Determines whether the window will automatically enable the close flag when
            ///         the user activates the close button on the frame.
            /// 
            /// @return true if and only if the window will automatically enable the close flag when
            ///         the user activates the close button
            ///
            virtual bool is_user_closable(void) const noexcept override;

            /// 
            /// @brief  Sets whether the window will automatically enable the close flag when the
            ///         user activates the close button on the frame.
            /// 
            /// @param  is_user_closable    a true value indicates that the window should
            ///                             automatically enable the close flag
            /// 
            /// @return a pointer to the window for chaining
            ///
            virtual managed_window *set_user_closable(bool is_user_closable) noexcept override;

            /// 
            /// @brief  Determines whether the user can interact with the window's frame to resize
            ///         it.
            /// 
            /// @return true if and only if the user can interact with the frame to resize it
            /// 
            /// @throw  exception if an error occured determining whether the window is user
            ///         resizable
            ///
            virtual bool is_user_resizable(void) const override = 0;

            /// 
            /// @brief  Sets whether the user can interact with the window's frame to resize it.
            /// 
            /// @param  is_user_resizable   whether the user can interact with the frame to resize
            ///                             it
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occured setting whether the window is user resizable
            ///
            virtual managed_window *set_user_resizable(bool is_user_resizable) override = 0;

            /// 
            /// @brief  Determines the title of the window displayed on the frame.
            /// 
            /// @return the title of the window
            /// 
            /// @throw  exception if an error occurs determining the title of the window
            ///
            virtual std::string title(void) const override = 0;

            /// 
            /// @brief  Sets the title of the window displayed on the frame.
            /// 
            /// @param  title   the title of the window
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs setting the title
            ///
            virtual managed_window *set_title(const std::string &title) override = 0;

            /// 
            /// @brief  Determines whether the window has input focus. This also generally means
            ///         that it in the front in terms of z-position, but this is
            ///         implementation-dependent.
            /// 
            /// @return true if and only if the window has input focus
            /// 
            /// @throw  exception if an error occurs determining whether the window has input focus
            ///
            virtual bool has_focus(void) const override = 0;

            /// 
            /// @brief  Gives the window input focus if it did not have it previously. This also
            ///         generally means that it will be brought to the front in terms of z-position,
            ///         but this is implementation-dependent.
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs giving the window input focus
            ///
            virtual managed_window *focus(void) override = 0;

            /// 
            /// @brief  Determines whether the window has a frame.
            ///
            /// @return true if and only if the window has a frame
            ///
            /// @throw  exception if an error occurs determining whether the window has a frame
            /// 
            virtual bool framed(void) const override = 0;

            /// 
            /// @brief  Sets whether the window has a frame.
            /// 
            /// @param  framed  true if the window should have a frame
            /// 
            /// @return a pointer to the window for chaining
            /// 
            /// @throw  exception if an error occurs determining whether the window has a frame
            ///
            virtual managed_window *set_framed(bool framed) override = 0;

            /// 
            /// @brief  Determines the size of the frame as border measurements. If the window is
            ///         frameless, all dimensions of the border will be 0.
            ///         
            /// @return the size of the frame as border measurements
            /// 
            /// @throw  exception if an error occurs determining the size of the frame
            ///
            virtual border_t frame_border(void) const override = 0;

            /// 
            /// @brief  Determines the position of the top left corner of the frame originating from
            ///         the top left corner of the monitor the window resides in. If the window is
            ///         frameless, the frame position is the same as the surface position.
            ///  
            /// @return the position of the frame
            /// 
            /// @throw  exception if an error occurs determining the position of the frame
            /// 
            virtual pos2_t frame_pos(void) const override = 0;
    };
}

#endif

/**
 * @file    managed_window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 4, 2023
 * 
 * @brief   Header for an abstract class that represents a graphical user interface window that is
 *          managed by a window manager. A window is immediately alive (open) upon its object's
 *          construction, however, it may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef MANAGED_WINDOW_H_HEADER_GUARD
#define MANAGED_WINDOW_H_HEADER_GUARD

#include "../../surfaces/native_surface_i.hpp"
#include "../nonatomic_window_i.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a graphical user interface window that is managed by a window manager. A
     *          window is immediately alive (open) upon its object's construction, however, it may
     *          be closed before its object's destruction.
     */
    class managed_window : public nonatomic_window_i, public native_surface_i
    {
        private:
            /**
             * @brief   Denotes whether the window is alive (open) or dead (closed) represented by
             *          the values true or false respectively.
             */
            bool m_is_alive;

            /**
             * @brief   Denotes whether the window can be closed by the user.
             */
            bool m_is_user_closable;

            /**
             * @brief   Native platform-dependent data about the window's display surface.
             */
            native_surface_data_t m_native_data;

            /**
             * @brief   Creates the native data for the window's display surface.
             * 
             * @throw   runtime_error if the operating system is not supported
             */
            void init_natives(void);

        protected:
            /**
             * @brief   Creates a managed window. The title, position, and size are set to default
             *          values. When the window is created it is immediately alive. Assuming that it
             *          is visible and window manager events are polled, it will begin displaying
             *          upon creation.
             * 
             * @throw   runtime_error if an error occurs creating the window
             */
            managed_window(void);

            /**
             * @brief   Creates a managed window. When the window is created it is immediately
             *          alive. Assuming that it is visible and window manager events are polled, it
             *          will begin displaying upon creation.
             * 
             * @param   title   the title bar content string
             * @param   x       the initial x-position
             * @param   y       the initial y-position
             * @param   width   the initial width
             * @param   height  the initial height
             * 
             * @throw   runtime_error if an error occurs creating the window
             */
            managed_window(const string &title, int x, int y, int width, int height);

            /**
             * @brief   Destructs the window object.
             */
            virtual ~managed_window() noexcept;

            /**
             * @brief   Destroys the window (deallocates internal functionality and deems it dead
             *          and therefore closed). If the window was already closed, nothing happens.
             * 
             * @return  true if and only if the window was not already dead (closed)
             */
            virtual bool destroy(void) noexcept override = 0;

            /**
             * @brief   Sets the flag indicating whether the window should close the next time
             *          events are polled.
             * 
             * @param   should_close  true if the window should close, false if it should not close
             * 
             * @return  the previous value of the should close flag prior to setting
             */
            bool set_should_close(bool should_close) noexcept override = 0
            {
                // Store the previous value of the flag for returning.
                bool previous_value = should_close;

                // Set the flag to the new value.
                m_is_user_closable = should_close;

                // Return the previous value.
                return previous_value;
            }

        public:
            /**
             * @brief   A window should not be copied as this copy would be shallow. Therefore, this
             *          functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            managed_window(const managed_window &other) noexcept = delete;

            /**
             * @brief   A window should not be moved as this move would be shallow. Therefore, this
             *          functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            managed_window(managed_window &&other) noexcept = delete;

            /**
             * @brief   A window should not be copied as this copy would be shallow. Therefore, this
             *          functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            managed_window &operator=(const managed_window &other) noexcept = delete;

            /**
             * @brief   A window should not be moved as this move would be shallow. Therefore, this
             *          functionality is deleted.
             * 
             * @param   other   a separate window object
             */
            managed_window &operator=(managed_window &&other) noexcept = delete;

            /**
             * @brief   Determines the width of the window's display surface in pixels. Note that
             *          the surface is only the inner content area of the window, not the frame.
             * 
             * @return  the width of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t width(void) const noexcept override = 0;

            /**
             * @brief   Determines the height of the window's display surface in pixels. Note that
             *          the surface is only the inner content area of the window, not the frame.
             * 
             * @return  the height of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t height(void) const noexcept override = 0;

            /**
             * @brief   Sets the width of the window's display surface in pixels. The height is not
             *          affected. Note that the surface is only the inner content area of the
             *          window, not the frame. The frame will be resized appropriately to accomodate
             *          the change. 
             *           
             * 
             * @param   width   the new width of the surface in pixels
             * 
             * @return  the original width of the surface in pixels prior to this action
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t set_width(px_t width) noexcept override = 0;

            /**
             * @brief   Sets the height of the window's display surface in pixels. The width is not
             *          affected. Note that the surface is only the inner content area of the
             *          window, not the frame. The frame will be resized appropriately to accomodate
             *          the change. 
             * 
             * @param   height   the new height of the surface in pixels
             * 
             * @return  the original height of the surface in pixels prior to this action
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t set_height(px_t height) noexcept override = 0;

            /**
             * @brief   Sets the size of the surface in pixels. Both the width and height are
             *          affected. Note that the surface is only the inner content area of the
             *          window, not the frame. The frame will be resized appropriately to accomodate
             *          the change. 
             * 
             * @param   width   the new width of the surface in pixels
             * @param   height  the new height of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual void set_size(px_t width, px_t height) noexcept override = 0;

            /**
             * @brief   Determines whether the window is currently visible on the user's display.
             *          This will only account for whether the window visible in an absolute sense.
             *          Z-overlapping or minimization may cause the surface to appear out of view.
             *          These cases will not be considered hidden.
             * 
             * @return  whether the window is currently visible
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual bool is_visible(void) const noexcept override = 0;

            /**
             * @brief   Sets whether the window is currently visible on the user's display. A true
             *          value will make the window visible while a false value will hide the window.
             *          This will hide or show the window in an absolute sense. Z-overlapping or
             *          minimization may cause the window to appear out of view. These cases are not
             *          congruent with the functionality of this action.
             * 
             * @return  whether the window was visible prior to this action
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual bool set_visible(bool is_visible) noexcept override = 0;

            /**
             * @brief   Determines the x-position of the window's display surface in pixels. Note
             *          that the surface is only the inner content area of the window, not the
             *          frame. The coordinates are cartesian and originate from the upper left
             *          corner of the monitor that the window primarily resides in.
             * 
             * @return  the x-position of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t x(void) const noexcept override = 0;

            /**
             * @brief   Determines the y-position of the window's display surface in pixels. Note
             *          that the surface is only the inner content area of the window, not the
             *          frame. The coordinates are cartesian and originate from the upper left
             *          corner of the monitor that the window primarily resides in.
             * 
             * @return  the y-position of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t y(void) const noexcept override = 0;

            /**
             * @brief   Sets the x-position of the window's display surface in pixels. The
             *          y-position is not affected. The coordinates are cartesian and originate
             *          from the upper left corner of the monitor that the window primarily resides
             *          in. Note that the surface is only the inner content area of the window, not
             *          the frame. The frame will be repositioned appropriately to accomodate the
             *          change. 
             * 
             * @param   x   the new x-position of the surface in pixels
             * 
             * @return  the original x-position of the surface in pixels prior to this action
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t set_x(px_t x) noexcept override = 0;

            /**
             * @brief   Sets the y-position of the window's display surface in pixels. The
             *          x-position is not affected. The coordinates are cartesian and originate
             *          from the upper left corner of the monitor that the window primarily resides
             *          in. Note that the surface is only the inner content area of the window, not
             *          the frame. The frame will be repositioned appropriately to accomodate the
             *          change. 
             * 
             * @param   y   the new y-position of the surface in pixels
             * 
             * @return  the original y-position of the surface in pixels prior to this action
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual px_t set_y(px_t y) noexcept override = 0;

            /**
             * @brief   Sets the position of the window's display surface in pixels. Both the
             *          x-position and y-position are affected. The coordinates are cartesian and
             *          originate from the upper left corner of the monitor that the window 
             *          rimarily resides in. Note that the surface is only the inner content area of
             *          the window, not the frame. The frame will be repositioned appropriately to
             *          accomodate the change. 
             * 
             * @param   x   the new x-position of the surface in pixels
             * @param   y   the new y-position of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual void set_position(px_t x, px_t y) noexcept override = 0;

            /**
             * @brief   Determines whether the window is alive (as opposed to being closed).
             * 
             * @return  true if and only if the window is not closed
             */
            inline bool is_alive(void) const noexcept override
            {
                // Return the flag denoting whether the window is alive.
                return m_is_alive;
            }

            /**
             * @brief   Informs the window that it should close. Note that this does not guaruntee
             *          an immediate close. Window manager events must be polled to recognize that a
             *          close should take place.
             * 
             * @return  true if and only if the window was not already closed (or flagged to close)
             */
            inline bool close(void) noexcept override
            {
                // If the window is alive and not already flagged to close, set the flag indicating
                // that it should close.
                if (m_is_alive && !should_close())
                {
                    // Set the flag indicating that it should close. 
                    set_should_close(true);

                    // Return true indicating that the window has been flagged for closing.
                    return true;
                }

                // If the window was not alive, return false indicating that nothing happened. 
                return false;
            }

            /**
             * @brief   Determines whether the window will automatically enable the close flag when
             *          the user activates the close button on the frame.
             * 
             * @return  true if and only if the window will automatically enable the close flag when
             *          the user activates the close button
             */
            inline bool is_user_closable(void) const noexcept override
            {
                // Return the flag identifying whether the window is user closable.
                return m_is_user_closable;
            }

            /**
             * @brief   Sets whether the window will automatically enable the close flag when the
             *          user activates the close button on the frame.
             * 
             * @param   is_user_closable    a true value indicates that the window should
             *                              automatically enable the close flag
             * 
             * @return  the previous value of the user closable option prior to setting
             */
            inline bool set_user_closable(bool is_user_closable) noexcept override
            {
                // Store the previous value of the flag for returning.
                bool previous_value = is_user_closable;

                // Set the flag to the new value.
                m_is_user_closable = is_user_closable;

                // Return the previous value.
                return previous_value;
            }

            /**
             * @brief   Determines whether the user can interact with the window's frame to
             *          reposition it.
             * 
             * @return  true if and only if the user can interact with the frame to reposition it
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual bool is_user_movable(void) const noexcept override = 0;
            
            /**
             * @brief   Sets whether the user can interact with the window's frame to reposition it.
             * 
             * @param   is_user_movable whether the user can interact with the frame to
             *                          reposition it
             * 
             * @return  the previous value of the user movable option prior to setting
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual bool set_user_movable(bool is_user_movable) noexcept override = 0;

            /**
             * @brief   Determines whether the user can interact with the window's frame to resize
             *          it.
             * 
             * @return  true if and only if the user can interact with the frame to resize it
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual bool is_user_resizable(void) const noexcept override = 0;

            /**
             * @brief   Sets whether the user can interact with the window's frame to resize it.
             * 
             * @param   is_user_resizable   whether the user can interact with the frame to resize
             *                              it
             * 
             * @return  the previous value of the user resizable option prior to setting
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual bool set_user_resizable(bool is_user_resizable) noexcept override = 0;

            /**
             * @brief   Determines the title of the window displayed on the frame.
             * 
             * @return  the title of the window
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual string title(void) const noexcept override = 0;

            /**
             * @brief   Sets the title of the window displayed on the frame.
             * 
             * @param   title   the title of the window
             * 
             * @return  the previous title prior to setting
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            virtual string set_title(const string &title) const noexcept override = 0;

            /**
             * @brief   Determines whether the window should close the next time events are polled.
             * 
             * @return  true if the window should close
             */
            virtual bool should_close(void) const noexcept override = 0;

            /**
             * @brief   Performs any necessary updates for the window. This includes closing the
             *          window if a close was requested. If the window is closed, nothing happens.
             * 
             * @return  true if and only if the window is active (has not been closed)
             */
            virtual bool poll_events(void) noexcept override = 0;

            /**
             * @brief   Determines the name of the operating system the window resides on.
             * 
             * @return  The name string of the operating system
             */
            inline string native_os_name(void) const noexcept override
            {
                // Return the platform name macro from BX.
                return BX_PLATFORM_NAME;
            }

            /**
             * @brief   Returns native platform-dependent data about the window's display surface.
             *          A null display type pointer is acceptable on some systems. However, a null
             *          handle pointer indicates that the operating system is not supported.
             * 
             * @return  a structure of native surface data
             */
            native_surface_data_t native_data(void) const noexcept override;

            /**
             * @brief   Determines the version of SDL being used for the window.
             * 
             * @return  a structure containing components comprising the version of SDL being used
             */
            inline sdl_version_t sdl_version(void) const noexcept
            {
                // Create a version structure.
                sdl_version_t version;

                // Copy the SDL version information into the structure.
                SDL_VERSION(&version)

                // Return the version structure.
                return version;
            }
    };
}

#endif

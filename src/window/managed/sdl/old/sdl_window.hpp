/**
 * @file    sdl_window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents a graphical user interface window implemented with
 *          SDL. A window is immediately alive (open) upon its object's construction, however, it
 *          may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_WINDOW_H_HEADER_GUARD
#define SDL_WINDOW_H_HEADER_GUARD

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <bx/platform.h>
#include "../../graphics/surface/native_surface_i.hpp"
#include "../managed_window.hpp"
#include "sdl_types.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a graphical user interface window implemented with SDL. A window is
     *          immediately alive (open) upon its object's construction, however, it may be closed
     *          before its object's destruction.
     */
    class sdl_window : public managed_window, public native_surface_i
    {
        // The SDL manager class must be able to create and destroy windows.
        friend class sdl;

        private:
            /**
             * @brief   Denotes whether the window is alive (open) or dead (closed) represented by
             *          the values true or false respectively.
             */
            bool m_is_alive;

            /**
             * @brief   Denotes whether the window should close the next time events are polled.
             */
            bool m_should_close;

            /**
             * @brief   The internal SDL window pointer.
             */
            SDL_Window *m_internal_window;

            /**
             * @brief   Internal platform-dependent system information about the window.
             */
            SDL_SysWMinfo m_system_info;

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
             * @brief   Creates an SDL window. The title, position, and size are set to default
             *          values. When the window is created it is immediately active. Assuming that
             *          it is visible and SDL events are polled, it will begin displaying upon
             *          creation.
             * 
             * @throw   runtime_error if an error occurs creating the SDL window
             */
            sdl_window(void);

            /**
             * @brief   Creates an SDL window. When the window is created it is immediately active.
             *          Assuming that it is visible and SDL events are polled, it will begin
             *          displaying upon creation.
             * 
             * @param   title   the title bar content string
             * @param   x       the initial x-position
             * @param   y       the initial y-position
             * @param   width   the initial width
             * @param   height  the initial height
             * 
             * @throw   runtime_error if an error occurs creating the SDL window
             */
            sdl_window(const string &title, int x, int y, int width, int height);

            /**
             * @brief   Destroys the SDL window.
             */
            virtual ~sdl_window() noexcept;

            /**
             * @brief   Destroys the window (deallocates internal SDL functionality and deems it
             *          dead and therefore closed). If the window was already closed, nothing
             *          happens.
             * 
             * @return  true if and only if the window was not already dead (closed)
             */
            bool destroy(void) noexcept override;

        public:
            /**
             * @brief   An SDL window should not be copied as this copy would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window(const sdl_window &other) noexcept = delete;

            /**
             * @brief   An SDL window should not be moved as this move would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window(sdl_window &&other) noexcept = delete;

            /**
             * @brief   An SDL window should not be copied as this copy would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window &operator=(const sdl_window &other) noexcept = delete;

            /**
             * @brief   An SDL window should not be moved as this move would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window &operator=(sdl_window &&other) noexcept = delete;

            /**
             * @brief   Determines the width of the window's display surface in pixels. Note that
             *          the surface is only the inner content area of the window, not the frame.
             * 
             * @return  the width of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            px_t width(void) const noexcept override;

            /**
             * @brief   Determines the height of the window's display surface in pixels. Note that
             *          the surface is only the inner content area of the window, not the frame.
             * 
             * @return  the height of the surface in pixels
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            px_t height(void) const noexcept override;

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
            px_t set_width(px_t width) noexcept override;

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
            px_t set_height(px_t height) noexcept override;

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
            void set_size(px_t width, px_t height) noexcept override;

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
            bool is_visible(void) const noexcept override;

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
            bool set_visible(bool is_visible) noexcept override;

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
            px_t x(void) const noexcept override;

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
            px_t y(void) const noexcept override;

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
            px_t set_x(px_t x) noexcept override;

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
            px_t set_y(px_t y) noexcept override;

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
            void set_position(px_t x, px_t y) noexcept override;

            /**
             * @brief   Determines whether the user can interact with the window's frame to
             *          reposition it.
             * 
             * @return  true if and only if the user can interact with the frame to reposition it
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            bool is_user_movable(void) const noexcept override;
            
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
            bool set_user_movable(bool is_user_movable) noexcept override;

            /**
             * @brief   Determines whether the user can interact with the window's frame to resize
             *          it.
             * 
             * @return  true if and only if the user can interact with the frame to resize it
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            bool is_user_resizable(void) const noexcept override;

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
            bool set_user_resizable(bool is_user_resizable) noexcept override;

            /**
             * @brief   Determines whether the window is alive (as opposed to being closed).
             * 
             * @return  true if and only if the window is not closed
             */
            bool is_alive(void) const noexcept override;
        
            /**
             * @brief   Informs the window that it should close. Note that this does not guaruntee
             *          an immediate close. SDL events must be polled to recognize that a close
             *          should take place.
             * 
             * @return  true if and only if the window was not already closed (or flagged to close)
             */
            bool close(void) noexcept override;

            /**
             * @brief   Determines whether the window will automatically enable the close flag when
             *          the user activates the close button on the frame.
             * 
             * @return  true if and only if the window will automatically enable the close flag when
             *          the user activates the close button
             */
            bool is_user_closable(void) const noexcept override;

            /**
             * @brief   Sets whether the window will automatically enable the close flag when the
             *          user activates the close button on the frame.
             * 
             * @param   is_user_closable    a true value indicates that the window should
             *                              automatically enable the close flag
             * 
             * @return  the previous value of the user closable option prior to setting
             */
            bool set_user_closable(bool is_user_closable) noexcept override;

            /**
             * @brief   Determines the title of the window displayed on the frame.
             * 
             * @return  the title of the window
             * 
             * @warning Behavior is undefined if the window is closed and a segmentation fault is
             *          likely.
             */
            string title(void) const noexcept override;

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
            string set_title(const string &title) const noexcept override;

            /**
             * @brief   Determines whether the window should close the next time events are polled.
             * 
             * @return  true if the window should close
             */
            bool should_close(void) const noexcept override;

            /**
             * @brief   Performs any necessary updates for the window. This includes closing the
             *          window if a close was requested. If the window is closed, nothing happens.
             * 
             * @return  true if and only if the window is active (has not been closed)
             */
            bool poll_events(void) noexcept override;

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
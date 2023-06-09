/// 
/// @file       sdl_window.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 5, 2023
/// 
/// @brief      Header for a class that represents a graphical user interface window implemented
///             with SDL. A window is immediately alive (open) upon its object's construction,
///             however, it may be closed before its object's destruction.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_SDL_WINDOW_HEADER_GUARD
#define LEAF_SRC_SDL_WINDOW_HEADER_GUARD

// The class must be forward declared because there are circular includes between the SDL window
// manager and SDL window classes.
namespace leaf
{
    class sdl_window;
}

#include <SDL3/SDL_syswm.h>
#include "../../../utils/release_types.hpp"
#include "../../../graphics/surface/native_surface_i.hpp"
#include "../managed_window.hpp"
#include "sdl.hpp"
#include "sdl_window_event_manager.hpp"

/// 
/// @brief  The default width of an SDL window.
/// 
#define LEAF_SDL_WINDOW_DEFAULT_WIDTH (leaf::px_t)600

/// 
/// @brief  The default height of an SDL window.
/// 
#define LEAF_SDL_WINDOW_DEFAULT_HEIGHT (leaf::px_t)400

namespace leaf
{
    /// 
    /// @brief  Represents a graphical user interface window implemented with SDL. A window is
    ///         immediately alive (open) upon its object's construction, however, it may be closed
    ///         before its object's destruction.
    /// 
    class sdl_window : public managed_window, public native_surface_i
    {
        // The SDL window manager must be able to access hidden functionality of an SDL window.
        friend class sdl;

        private:
            /// 
            /// @brief  Denotes whether the window should close the next time events are polled.
            /// 
            bool m_should_close;

            /// 
            /// @brief  Denotes whether the window is resizable by the user.
            /// 
            bool m_is_user_resizable;

            /// 
            /// @brief  A pointer to the event manager for the window. The event manager holds
            ///         subscribed event handlers for the window.
            /// 
            sdl_window_event_manager *const m_event_manager;

            /// 
            /// @brief  The internal SDL 4-byte identifier of the window.
            /// 
            uint32_t m_id;

            /// 
            /// @brief  The internal SDL window pointer.
            /// 
            SDL_Window *m_internal_window;

            /// 
            /// @brief  Platform-dependent system information about the internal SDL window.
            /// 
            SDL_SysWMinfo m_system_info;

            /// 
            /// @brief  Native platform-dependent data about the window's display surface.
            /// 
            native_surface_data_t m_native_data;

            /// 
            /// @brief  Creates the native data for the window's display surface.
            /// 
            /// @throw  runtime_error if the operating system is not supported or the window handle
            ///         could not be obtained
            /// 
            void init_natives(void);

            /// 
            /// @brief  Sets the defaults presets of the window upon initialization.
            /// 
            void set_defaults(void) noexcept;

        protected:
            /// 
            /// @brief  Destroys the window (deallocates internal SDL functionality and deems it
            ///         dead and therefore closed). If the window was already closed, nothing
            ///         happens.
            /// 
            /// @return true if and only if the window was not already dead (closed)
            /// 
            bool destroy(void) noexcept override;

            /// 
            /// @brief  Determines whether the window should close the next time events are polled.
            /// 
            /// @return true if the window should close
            /// 
            virtual bool should_close(void) const noexcept override;

            /// 
            /// @brief  Sets the flag indicating whether the window should close the next time
            ///         events are polled.
            /// 
            /// @param  should_close    true if the window should close, false if it should not
            ///                         close
            /// 
            /// @return a pointer to the window for chaining
            /// 
            virtual managed_window *set_should_close(bool should_close) noexcept override;

            /// 
            /// @brief  Performs any necessary updates for the window. This includes closing the
            ///         window if a close was requested. If the window is closed, nothing happens.
            /// 
            /// @return true if and only if the window is active (has not been closed), if this
            ///         action causes the window to close or it was already closed, false will be
            ///         returned
            /// 
            virtual bool poll_events(void) noexcept override;

            /// 
            /// @brief  Determines the window's 4-byte internal SDL identifier.
            /// 
            /// @return the 4-byte ID
            /// 
            uint32_t id(void) const noexcept;

            /// 
            /// @brief      Handles an SDL event that is relevant to this window (i.e. this window
            ///             is the subject of the event).
            /// 
            /// @param      event   the SDL event
            /// 
            /// @warning    There is no check in place to ensure this event is relevant to this
            ///             window. It is the duty of the caller to responsibly pass only events
            ///             where the subject is this window.
            /// 
            void handle_sdl_event(const SDL_Event &event) noexcept;

        public:
            /// 
            /// @brief  Creates an SDL window. The title, position, and size are set to default
            ///         values. This often means it will be centered in the monitor it resides in
            ///         but this cannot be assumed on all operating systems. When the window is
            ///         created it is immediately active. Assuming that it is visible and SDL events
            ///         are polled, it will begin displaying upon creation.
            /// 
            /// @throw  runtime_error if an error occurs creating the SDL window
            /// 
            sdl_window(void);

            /// 
            /// @brief  Creates an SDL window. The position is set to a default value. This often
            ///         means it will be centered in the monitor it resides in but this cannot be
            ///         assumed on all operating systems. When the  window is created it is
            ///         immediately active. Assuming that it is visible and SDL events are polled,
            ///         it will begin displaying upon creation.
            /// 
            /// @param  title   the title bar content string
            /// @param  width   the initial width
            /// @param  height  the initial height
            /// 
            /// @throw  runtime_error if an error occurs creating the SDL window
            /// 
            sdl_window(const std::string &title, int width, int height);

            /// 
            /// @brief  Creates an SDL window. When the window is created it is immediately active.
            ///         Assuming that it is visible and SDL events are polled, it will begin
            ///         displaying upon creation.
            /// 
            /// @param  title   the title bar content string
            /// @param  x       the initial x-position
            /// @param  y       the initial y-position
            /// @param  width   the initial width
            /// @param  height  the initial height
            /// 
            /// @throw  runtime_error if an error occurs creating the SDL window
            /// 
            sdl_window(const std::string &title, int x, int y, int width, int height);

            /// 
            /// @brief  Destructs the SDL window. The underlying SDL window is destroyed if it is
            ///         not already dead.
            /// 
            virtual ~sdl_window() noexcept;

            /// 
            /// @brief      Determines the bounds of the window's display surface in pixel
            ///             measurements. Note that the surface is only the inner content area of
            ///             the window, not the frame.
            /// 
            /// @return     the bounds of the window's display surface
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            ///
            virtual bounds2_t bounds(void) const noexcept override;

            /// 
            /// @brief      Sets the width of the window's display surface in pixels. The height is
            ///             not affected. Note that the surface is only the inner content area of
            ///             the window, not the frame. The frame will be resized appropriately to
            ///             accomodate the change.
            /// 
            /// @param      width   the new width of the surface in pixels
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_width(px_t width) noexcept override;

            /// 
            /// @brief      Sets the height of the window's display surface in pixels. The width is
            ///             not affected. Note that the surface is only the inner content area of
            ///             the window, not the frame. The frame will be resized appropriately to
            ///             accomodate the change. 
            /// 
            /// @param      height  the new height of the surface in pixels
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_height(px_t height) noexcept override;

            /// 
            /// @brief      Sets the size of the surface in pixels. Both the width and height are
            ///             affected. Note that the surface is only the inner content area of the
            ///             window, not the frame. The frame will be resized appropriately to
            ///             accomodate the change. 
            /// 
            /// @param      width   the new width of the surface in pixels
            /// @param      height  the new height of the surface in pixels
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_size(px_t width, px_t height) noexcept override;

            /// 
            /// @brief      Determines whether the window is currently visible on the user's
            ///             display. This will only account for whether the window visible in an
            ///             absolute sense. Z-overlapping or minimization may cause the surface to
            ///             appear out of view. These cases will not be considered hidden.
            /// 
            /// @return     whether the window is currently visible
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual bool is_visible(void) const noexcept override;

            /// 
            /// @brief      Sets whether the window is currently visible on the user's display. A
            ///             true value will make the window visible while a false value will hide
            ///             the window. This will hide or show the window in an absolute sense.
            ///             Z-overlapping or minimization may cause the window to appear out of
            ///             view. These cases are not congruent with the functionality of this
            ///             action.
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_visible(bool is_visible) noexcept override;

            /// 
            /// @brief      Determines the position of the top left corner of the window's display
            ///             surface. Coordinates are cartesian and originate from the top left
            ///             corner of the monitor the window resides in.
            /// 
            /// @return     the position of the window's display surface
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual pos2_t pos(void) const noexcept override;

            /// 
            /// @brief      Sets the x-position of the window's display surface in pixels. The
            ///             y-position is not affected. The coordinates are cartesian and originate
            ///             from the upper left corner of the monitor that the window primarily
            ///             resides in. Note that the surface is only the inner content area of the
            ///             window, not the frame. The frame will be repositioned appropriately to
            ///             accomodate the change.
            /// 
            /// @param      x   the new x-position of the surface in pixels
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_x(px_t x) noexcept override;

            /// 
            /// @brief      Sets the y-position of the window's display surface in pixels. The
            ///             x-position is not affected. The coordinates are cartesian and originate
            ///             from the upper left corner of the monitor that the window primarily
            ///             resides in. Note that the surface is only the inner content area of the
            ///             window, not the frame. The frame will be repositioned appropriately to
            ///             accomodate the change.
            /// 
            /// @param      y   the new y-position of the surface in pixels
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_y(px_t y) noexcept override;

            /// 
            /// @brief      Sets the position of the window's display surface in pixels. Both the
            ///             x-position and y-position are affected. The coordinates are cartesian
            ///             and originate from the upper left corner of the monitor that the window 
            ///             rimarily resides in. Note that the surface is only the inner content
            ///             area of the window, not the frame. The frame will be repositioned
            ///             appropriately to accomodate the change.
            /// 
            /// @param      x   the new x-position of the surface in pixels
            /// @param      y   the new y-position of the surface in pixels
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_pos(px_t x, px_t y) noexcept override;

            /// 
            /// @brief      Determines whether the user can interact with the window's frame to
            ///             resize it.
            /// 
            /// @return     true if and only if the user can interact with the frame to resize it
            /// 
            virtual bool is_user_resizable(void) const noexcept override;

            /// 
            /// @brief      Sets whether the user can interact with the window's frame to resize it.
            /// 
            /// @param      is_user_resizable   whether the user can interact with the frame to
            ///                                 resize it
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_user_resizable(bool is_user_resizable) noexcept override;

            /// 
            /// @brief      Determines the title of the window displayed on the frame.
            /// 
            /// @return     the title of the window
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual std::string title(void) const noexcept override;

            /// 
            /// @brief      Sets the title of the window displayed on the frame.
            /// 
            /// @param      title   the title of the window
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual sdl_window *set_title(const std::string &title) noexcept override;

            /// 
            /// @brief   Determines whether the window has input focus. This also generally means
            ///          that it in the front in terms of z-position.
            /// 
            /// @return  true if and only if the window has input focus
            /// 
            virtual bool has_focus(void) const noexcept override;

            /// 
            /// @brief   Gives the window input focus if it did not have it previously. It will be
            ///          brought to the front in terms of z-position.
            /// 
            /// @return  a pointer to the window for chaining
            /// 
            virtual sdl_window *focus(void) noexcept override;

            /// 
            /// @brief      Determines whether the window has a frame.
            ///
            /// @return     true if and only if the window has a frame
            ///
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual bool framed(void) const noexcept override;

            /// 
            /// @brief      Sets whether the window has a frame.
            /// 
            /// @param      framed  true if the window should have a frame
            /// 
            /// @return     a pointer to the window for chaining
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            ///
            virtual sdl_window *set_framed(bool framed) noexcept override;

            /// 
            /// @brief      Determines the size of the frame as border measurements. If the window
            ///             is frameless, all dimensions of the border will be 0.
            ///         
            /// @return     the size of the frame as border measurements
            /// 
            /// @throw      runtime_error if the size of the frame border could not be determined on
            ///             the operating system
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            ///
            virtual border_t frame_border(void) const override;

            /// 
            /// @brief      Determines the position of the top left corner of the frame originating
            ///             from the top left corner of the monitor the window resides in. If the
            ///             window is frameless, the frame position is the same as the surface
            ///             position.
            ///  
            /// @return     the position of the frame
            /// 
            /// @throw      runtime_error if the position of the frame could not be determined on
            ///             the operating system
            /// 
            /// @warning    Behavior is undefined if the window is closed and a segmentation fault
            ///             is likely.
            /// 
            virtual pos2_t frame_pos(void) const override;

            /// 
            /// @brief      Returns a pointer to the window's event manager. The event manager can
            ///             be used to subscribe event handlers.
            ///
            /// @return     a pointer to the window's event manager
            /// 
            /// @warning    The event manager object is destroyed when the window object is
            ///             destroyed. The pointer will lead to a null object after the window
            ///             object is destroyed and a segmentation fault will occur.
            /// 
            virtual sdl_window_event_manager *event_manager(void) const noexcept override;

            /// 
            /// @brief   Determines the name of the operating system the window resides on.
            /// 
            /// @return  The name string of the operating system
            /// 
            virtual std::string native_os_name(void) const noexcept override;

            /// 
            /// @brief   Returns native platform-dependent data about the window's display surface.
            ///          A null display type pointer is acceptable on some systems. However, a null
            ///          handle pointer indicates that the operating system is not supported.
            /// 
            /// @return  a structure of native surface data
            /// 
            virtual native_surface_data_t native_data(void) const noexcept override;

            /// 
            /// @brief   Determines the version of SDL being used for the window.
            /// 
            /// @return  a structure containing components comprising the version of SDL being used
            /// 
            inline utl::release_version_t sdl_version(void) const noexcept
            {
                // Create an SDL version structure.
                SDL_version version;

                // Copy the SDL version information into the structure.
                SDL_VERSION(&version)

                // Return a release structure copied from the SDL version structure.
                return {version.major, version.minor, version.patch};
            }
    };
}

#endif

/// 
/// @file       window_event_manager.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 12, 2023
/// 
/// @brief      Header for a class that represents a manager for window events. Event handlers can
///             be subscribed and unsubscribed. Windows can notify the manager of events.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_WINDOW_EVENT_MANAGER_HEADER_GUARD
#define LEAF_SRC_WINDOW_EVENT_MANAGER_HEADER_GUARD

#include <set>
#include "../utils/unique.hpp"
#include "../event_handler/window_event_handler_i.hpp"
#include "../event_handler/key_event_handler_i.hpp"

namespace leaf
{
    ///
    /// @brief  Represents a manager for window events. Event handlers can be subscribed and
    ///         unsubscribed. Windows can notify the manager of events.
    ///
    class window_event_manager : public utl::unique,
        virtual protected window_event_handler_i, virtual protected key_event_handler_i
    {
        private:
            /// 
            /// @brief  A set containing all of the subscribed window event handlers.
            /// 
            std::set<window_event_handler_i *> m_window_event_handlers;

            /// 
            /// @brief  A set containing all of the subscribed keybaord event handlers.
            /// 
            std::set<key_event_handler_i *> m_key_event_handlers;
        
        protected:
            /// 
            /// @brief  Notifies all handlers that the window was closed either by the user or
            ///         automatically.
            /// 
            virtual void closed(void) noexcept override;

            /// 
            /// @brief  Notifies all handlers that the window was resized either by the user or
            ///         automatically.
            /// 
            /// @param  new_bounds      a bounding rectangle defining the new width and height of
            ///                         the resized window display surface
            /// 
            virtual void resized(const bounds2_t &new_bounds) noexcept override;

            /// 
            /// @brief  Notifies all handlers that the window was moved either by the user or
            ///         automatically.
            /// 
            /// @param  new_pos         a position defining the new x-position and y-position in
            ///                         pixels of the window's display surface after the move
            /// @param  new_frame_pos   a position defining the new x-position and y-position in
            ///                         pixels of the window's frame after the move
            /// 
            virtual void moved(
                const pos2_t &new_pos, const pos2_t &new_frame_pos) noexcept override;
            
            /// 
            /// @brief  Notifies all handlers that the window was hidden either by the user or
            ///         automatically.
            /// 
            virtual void hidden(void) noexcept override;

            /// 
            /// @brief  Notifies all handlers that the window was shown either by the user or
            ///         automatically.
            /// 
            virtual void shown(void) noexcept override;

            /// 
            /// @brief  Notifies all handlers that the window was minimized either by the user or
            ///         automatically.
            /// 
            virtual void minimized(void) noexcept override;
            
            /// 
            /// @brief  Notifies all handlers that the window was maximized either by the user or
            ///         automatically.
            /// 
            /// @param  user_initiated  true if and only if the maximization was initated by the
            ///                         user as opposed to being automatic
            /// 
            virtual void maximized(void) noexcept override;

            /// 
            /// @brief  Notifies all handlers that the window entered fullscreen mode either by the
            ///         user or automatically.
            /// 
            virtual void entered_fullscreen(void) noexcept override;

            /// 
            /// @brief  Notifies all handlers that the window exited fullscreen mode either by the
            ///         user or automatically.
            /// 
            virtual void exited_fullscreen(void) noexcept override;

        public:
            /// 
            /// @brief  Destructs the window event manager.
            /// 
            /// @note   There are no resources to manually destroy, the destructor is explicitly
            ///         declared default to ensure that it is virtual.
            /// 
            virtual ~window_event_manager() noexcept = default;
            
            /// 
            /// @brief  Subscribes a window event handler.
            /// 
            /// @param  window_event_handler    a pointer to the new window event handler
            /// 
            /// @return true if and only if the event handler was not already subscribed
            /// 
            bool subscribe(window_event_handler_i *window_event_handler) noexcept;
            
            /// 
            /// @brief  Subscribes a keyboard event handler.
            /// 
            /// @param  key_event_handler   a pointer to the new keyboard event handler
            /// 
            /// @return true if and only if the event handler was not already subscribed
            /// 
            bool subscribe(key_event_handler_i *key_event_handler) noexcept;

            /// 
            /// @brief  Unsubscribes a window event handler.
            /// 
            /// @param  window_event_handler    a pointer to the window event handler to remove
            /// 
            /// @return false if and only if the event handler was not subscribed
            /// 
            bool unsubscribe(window_event_handler_i *window_event_handler) noexcept;

            /// 
            /// @brief  Unsubscribes a keyboard event handler.
            /// 
            /// @param  key_event_handler   a pointer to the keyboard event handler to remove
            /// 
            /// @return false if and only if the event handler was not subscribed
            /// 
            bool unsubscribe(key_event_handler_i *key_event_handler) noexcept;
    };
}

#endif

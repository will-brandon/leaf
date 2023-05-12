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
#include "window_i.hpp"
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
        // Windows must be able to create, destroy, and notify event managers.
        friend class window_i;

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
            /// @brief  Creates a new window event manager. By default, no event handlers are
            ///         subscribed.
            /// 
            /// @note   The default constructor will suffice, it is only explicitly declared to
            ///         ensure that it is protetced as opposed to public.
            /// 
            window_event_manager(void) noexcept = default;

            /// 
            /// @brief  Destroys the window event manager.
            /// 
            /// @note   The default destructor will suffice, it is only explicitly declared to
            ///         ensure that it is protetced as opposed to public.
            /// 
            virtual ~window_event_manager() noexcept = default;

        public:
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

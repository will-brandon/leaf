///
/// @file       window_event_manager.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 12, 2023
///
/// @brief      Implementation for a class that represents a manager for window events. Event
///             handlers can be subscribed and unsubscribed. Windows can notify the manager of
///             events.
///
/// @copyright  Copyright (c) 2023
///

#include "window_event_manager.hpp"

namespace leaf
{
    bool window_event_manager::subscribe(window_event_handler_i *window_event_handler) noexcept
    {
        // Add the event handler to the set so that it is subscribed to notifications.
        m_window_event_handlers.insert(window_event_handler);
    }
            
    bool window_event_manager::subscribe(key_event_handler_i *key_event_handler) noexcept
    {
        // Add the event handler to the set so that it is subscribed to notifications.
        m_key_event_handlers.insert(key_event_handler);
    }

    bool window_event_manager::unsubscribe(window_event_handler_i *window_event_handler) noexcept
    {
        // Remove the event handler from the set so that it is no longer subscribed to
        // notifications.
        m_window_event_handlers.erase(window_event_handler);
    }

    bool window_event_manager::unsubscribe(key_event_handler_i *key_event_handler) noexcept
    {
        // Remove the event handler from the set so that it is no longer subscribed to
        // notifications.
        m_key_event_handlers.erase(key_event_handler);
    }
}

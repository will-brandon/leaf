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
    void window_event_manager::closed(void) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->closed();
        }
    }

    void window_event_manager::resized(const bounds2_t &new_bounds) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->resized(new_bounds);
        }
    }

    void window_event_manager::moved(const pos2_t &new_pos, const pos2_t &new_frame_pos) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->moved(new_pos, new_frame_pos);
        }
    }
            
    void window_event_manager::hidden(void) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->hidden();
        }
    }

    void window_event_manager::shown(void) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->shown();
        }
    }

    void window_event_manager::minimized(void) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->minimized();
        }
    }
            
    void window_event_manager::maximized() noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->maximized(void);
        }
    }

    void window_event_manager::entered_fullscreen(void) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->entered_fullscreen();
        }
    }

    void window_event_manager::exited_fullscreen(void) noexcept
    {
        // Loop through all window event handlers and notify them of the event.
        for (window_event_handler_i *handler : m_window_event_handlers)
        {
            handler->exited_fullscreen();
        }
    }

    bool window_event_manager::subscribe(window_event_handler_i *window_event_handler) noexcept
    {
        // Add the event handler to the set so that it is subscribed to notifications. Return the
        // second item in the return pair identifying whether the handler was inserted or if it
        // already was in the set.
        return m_window_event_handlers.insert(window_event_handler).second;
    }
            
    bool window_event_manager::subscribe(key_event_handler_i *key_event_handler) noexcept
    {
        // Add the event handler to the set so that it is subscribed to notifications. Return the
        // second item in the return pair identifying whether the handler was inserted or if it
        // already was in the set.
        return m_key_event_handlers.insert(key_event_handler).second;
    }

    bool window_event_manager::unsubscribe(window_event_handler_i *window_event_handler) noexcept
    {
        // Remove the event handler from the set so that it is no longer subscribed to
        // notifications. Return the number of erased items cast to a boolean so that it will yield
        // false if no item could be erased.
        return m_window_event_handlers.erase(window_event_handler);
    }

    bool window_event_manager::unsubscribe(key_event_handler_i *key_event_handler) noexcept
    {
        // Remove the event handler from the set so that it is no longer subscribed to
        // notifications. Return the number of erased items cast to a boolean so that it will yield
        // false if no item could be erased.
        return m_key_event_handlers.erase(key_event_handler);
    }
}

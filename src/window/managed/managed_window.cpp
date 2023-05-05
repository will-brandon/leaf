/**
 * @file    managed_window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 5, 2023
 * 
 * @brief   Implementation for an abstract class that represents a graphical user interface window
 *          that is managed by a window manager. A window is immediately alive (open) upon its
 *          object's construction, however, it may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#include "managed_window.hpp"

using namespace std;

namespace leaf
{

    bool managed_window::set_should_close(bool should_close) noexcept
    {
        // Store the previous value of the flag for returning.
        bool previous_value = should_close;

        // Set the flag to the new value.
        m_is_user_closable = should_close;

        // Return the previous value.
        return previous_value;
    }

    bool managed_window::is_alive(void) const noexcept
    {
        // Return the flag denoting whether the window is alive.
        return m_is_alive;
    }

    bool managed_window::close(void) noexcept
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

    bool managed_window::is_user_closable(void) const noexcept
    {
        // Return the flag identifying whether the window is user closable.
        return m_is_user_closable;
    }
    
    bool managed_window::set_user_closable(bool is_user_closable) noexcept
    {
        // Store the previous value of the flag for returning.
        bool previous_value = is_user_closable;

        // Set the flag to the new value.
        m_is_user_closable = is_user_closable;

        // Return the previous value.
        return previous_value;
    }
}
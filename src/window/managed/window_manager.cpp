/**
 * @file    window_manager.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Implementation for an abstract class that represents a manager for graphical user
 *          interface windows. The class creates a singleton object, i.e. only one window manager
 *          object can be created.
 *
 * @copyright Copyright (c) 2023
 */

#include "window_manager.hpp"

using namespace std;

namespace leaf
{
    const set<managed_window *> &window_manager::windows(void) const noexcept
    {
        // Return a reference to the set of managed windows.
        return m_windows;
    }

    size_t window_manager::poll_windows(void) const
    {
        // Initialize a living window counter.
        size_t living_window_count = 0;

        // For each window under management, poll its events and check whether it is still alive
        // after its events are polled.
        for (managed_window *window : m_windows)
        {
            // Try to poll the window's events. If the window is alive when events are polled and is
            // still alive after events are polled, increment the counter.
            if (window->poll_events())
            {
                living_window_count++;
            }
        }

        // Return the counter.
        return living_window_count;
    }

    size_t window_manager::window_count(void) const noexcept
    {
        // Count the number of windows in the set of windows.
        return m_windows.size();
    }

    size_t window_manager::living_window_count(void) const noexcept
    {
        // Initialize a living window counter.
        size_t living_window_count = 0;

        // For each window under management, check if it is alive.
        for (const managed_window *window : m_windows)
        {
            // If the window is alive, increment the counter.
            if (window->is_alive())
            {
                living_window_count++;
            }
        }

        // Return the counter.
        return living_window_count;
    }
}
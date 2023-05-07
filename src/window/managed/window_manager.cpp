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

using namespace std;

#include "window_manager.hpp"

namespace leaf
{
    size_t window_manager::window_count(void) const noexcept
    {
        // Count the number of windows in the set of windows.
        return m_windows.size();
    }

    size_t window_manager::living_window_count(void) const noexcept
    {
        // Initialize a window counter.
        size_t count = 0;

        // For each window under management, check if it is alive.
        for (const managed_window *window : m_windows)
        {
            // If the window is alive, increment the counter.
            if (window->is_alive())
            {
                count++;
            }
        }

        // Return the counter.
        return count;
    }
}
/**
 * @file    window_manager.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 6, 2023
 * 
 * @brief   Header for an abstract class that represents a manager for graphical user interface
 *          windows. The class creates a singleton object, i.e. only one window manager object can
 *          be created.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef WINDOW_MANAGER_H_HEADER_GUARD
#define WINDOW_MANAGER_H_HEADER_GUARD

#include <set>
#include "managed_window.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a manager for graphical user interface windows. The class creates a
     *          singleton object, i.e. only one window manager object can be created.
     */
    class window_manager
    {
        private:
            /**
             * @brief   Tracks the set of all windows being managed.
             */
            set<managed_window *> m_windows;

        public:
            /**
             * @brief   Determines how many windows are being managed.
             * 
             * @return  the number of windows being managed
             */
            inline size_t window_count(void) const noexcept
            {
                // Count the number of windows in the set of windows.
                return m_windows.size();
            }

            /**
             * @brief   Determines how many managed windows are alive (not closed).
             * 
             * @return  the number of living managed windows
             */
            inline size_t living_window_count(void) const noexcept
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
    };
}

#endif

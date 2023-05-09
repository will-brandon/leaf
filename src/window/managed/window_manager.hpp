/// 
/// @file       window_manager.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 6, 2023
/// 
/// @brief      Header for an abstract class that represents a manager for graphical user interface
///             windows. The class creates a singleton object, i.e. only one window manager object
///             can be created.
///
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_WINDOW_MANAGER_HEADER_GUARD
#define LEAF_SRC_WINDOW_MANAGER_HEADER_GUARD

// The class must be forward declared because there are circular includes between the window manager
// and managed window classes.
namespace leaf
{
    class window_manager;
}

#include <set>
#include "managed_window.hpp"

namespace leaf
{
    /// 
    /// @brief  Represents a manager for graphical user interface windows. The class creates a
    ///         singleton object, i.e. only one window manager object can be created.
    /// 
    class window_manager
    {
        private:
            /// 
            /// @brief  Keeps a pointer for each window being managed.
            /// 
            std::set<managed_window *> m_windows;
        
        protected:
            /// 
            /// @brief  Returns a reference to the set of all windows under management.
            /// 
            /// @return a reference to the set of all windows under management
            /// 
            const std::set<managed_window *> &windows(void) const noexcept;

            /// 
            /// @brief  Adds the given window to the set of managed windows.
            /// 
            /// @param  window  a pointer to the window to start managing
            /// 
            /// @return true if and only if the window was not already being managed
            /// 
            /// @throw  runtime exception if the given window pointer is null
            /// 
            bool register_window(managed_window *window);
            
            /// 
            /// @brief  Removes the given window from the set of managed windows.
            /// 
            /// @param  window  a pointer to the window to stop managing
            /// 
            /// @return true if and only if the window was being managed
            /// 
            /// @throw  runtime exception if the given window pointer is null
            /// 
            bool unregister_window(managed_window *window);

            /// 
            /// @brief  Polls the events of all living managed windows.
            /// 
            /// @return the number of windows that are alive after polling is finished
            /// 
            /// @throw  exception if any window failed to poll events
            /// 
            size_t poll_windows(void) const;

        public:
            /// 
            /// @brief  Determines how many windows are being managed.
            /// 
            /// @return the number of windows being managed
            /// 
            size_t window_count(void) const noexcept;

            /// 
            /// @brief  Determines how many managed windows are alive (not closed).
            /// 
            /// @return the number of living managed windows
            /// 
            size_t living_window_count(void) const noexcept;

            /// 
            /// @brief  Performs updates on the window manager. This will poll the events of each
            ///         individual living managed window as well as perform any necessary window
            ///         library calls.
            /// 
            /// @return true if and only if at least one living window is under management
            /// 
            /// @throw  exception if an error occured polling events
            /// 
            virtual bool poll_events(void) = 0;

            /// 
            /// @brief  Performs a close call on all living managed windows. Note that this does not
            ///         immediately destroy them, it simply instructs them to close the next time
            ///         their events are polled. After this call and events for all windows are
            ///         polled, the number of living windows should be 0.
            /// 
            /// @return The number of living windows that had not previously been flagged for
            ///         closing that were newly flagged
            /// 
            size_t close_all_windows(void) noexcept;
    };
}

#endif

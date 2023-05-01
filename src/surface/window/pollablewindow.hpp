/**
 * @file    pollablewindow.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 30, 2023
 * 
 * @brief   Header for a class that represents an interface specification for a graphical user
 *          interface window native to the operating system it resides on.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef POLLABLE_WINDOW_H_HEADER_GUARD
#define POLLABLE_WINDOW_H_HEADER_GUARD

#include "window.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window native
     *          to the operating system it resides on.
     */
    class pollable_window : public window
    {
        private:
            /**
             * @brief   A flag denoting whether the window is alive (as opposed to being closed).
             */
            bool m_is_alive;

            /**
             * @brief   A flag denoting whether the window should close the next time events are
             *          polled.
             */
            bool m_should_close;

        protected:
            /**
             * @brief   Determines whether the window is alive (as opposed to being closed).
             * 
             * @return  true if and only if the window is not closed.
             */
            bool is_alive(void) const noexcept override;
            
            /**
             * @brief   Destroys the window (deallocates internal functionality and deems it
             *          dead and therefore closed).
             * 
             * @return  true if and only if the window was not already dead (closed)
             */
            virtual bool destroy(void) noexcept override = 0;

            /**
             * @brief   Determines whether the window should close the next time SDL events are
             *          polled.
             * 
             * @return true if the window should close
             */
            bool should_close(void) const noexcept;

            /**
             * @brief   Performs any necessary updates for the window. This includes closing the
             *          window if a close was requested.
             * 
             * @return  true if and only if the window is active (has not been closed)
             * 
             * @throw   runtime_exception if the window is not active
             */
            virtual bool poll_events(void) = 0;

        public:
            /**
             * @brief   Informs the window that it should close. Note that this does not guaruntee
             *          an immediate close. Events must be polled to recognize that a close should
             *          take place and perform the destruction.
             * 
             * @return  true if and only if the window was not already closed
             */
            bool close(void) noexcept override;

            /**
             * @brief   Determines whether the 
             * 
             * @return true 
             * @return false 
             */
            virtual bool auto_closing(void) const noexcept = 0;

            virtual void set_auto_closing(bool enabled) noexcept = 0;
    };
}

#endif

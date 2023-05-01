/**
 * @file    nonatomic_window_i.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 1, 2023
 * 
 * @brief   Header for an abstract class that represents an interface specification for a graphical
 *          user interface window that is managed by multiple threads. This results in a need for
 *          correspondence between threads, often a window driver thread and a graphics thread. This
 *          interaction occurs in the form of polling events that need updating and using flags to
 *          indicate necessary actions such as closing. A window is immediately alive (open) upon
 *          its object's construction, however, it may be closed before its object's destruction.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef NONATOMIC_WINDOW_I_H_HEADER_GUARD
#define NONATOMIC_WINDOW_I_H_HEADER_GUARD

#include "window_i.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window that is
     *          managed by multiple threads. This results in a need for correspondence between
     *          threads, often a window driver thread and a graphics thread. This interaction occurs
     *          in the form of polling events that need updating and using flags to indicate
     *          necessary actions such as closing. A window is immediately alive (open) upon its
     *          object's construction, however, it may be closed before its object's destruction.
     */
    class nonatomic_window_i : public window_i
    {
        protected:            
            /**
             * @brief   Destroys the window (deallocates internal functionality and deems it dead
             *          and therefore closed). If the window was already closed, nothing happens.
             * 
             * @return  true if and only if the window was not already dead (closed)
             * 
             * @throw   exception if an error occurs destroying the window
             */
            virtual bool destroy(void) = 0;

        public:
            /**
             * @brief   Determines whether the window should close the next time events are polled.
             * 
             * @return  true if the window should close
             * 
             * @throw   exception if an error occurs determining if the window should close
             */
            bool should_close(void) const;

            /**
             * @brief   Performs any necessary updates for the window. This includes closing the
             *          window if a close was requested. If the window is closed, nothing happens.
             * 
             * @return  true if and only if the window is active (has not been closed)
             * 
             * @throw   exception if an error occurs polling window events
             */
            virtual bool poll_events(void) = 0;

            /**
             * @brief   Determines whether the window will automatically enable the close flag when
             *          the user performs a close action on the user interface (This is often in
             *          the form of clicking a red 'x' button).
             * 
             * @return  true if and only if the window will automatically enable the close flag when
             *          the user performs a close action
             * 
             * @throw   exception if an error occurs determining whether the window will
             *          automatically enable the close flag
             */
            virtual bool is_user_closable(void) const noexcept = 0;

            /**
             * @brief   Sets whether the window will automatically enable the close flag when the
             *          user performs a close action on the user interface (This is often in the
             *          form of clicking a red 'x' button).
             * 
             * @param   is_user_closable    a true value indicates that the window should
             *                              automatically enable the close flag
             * 
             * @return  the previous value of the user closable option prior to setting
             * 
             * @throw   exception if an error occurs setting whether the window will automatically
             *          enable the close flag
             */
            virtual bool set_user_closable(bool is_user_closable) noexcept = 0;
    };
}

#endif

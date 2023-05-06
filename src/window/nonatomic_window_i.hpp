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
    class nonatomic_window_i : public virtual window_i
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
            virtual bool should_close(void) const = 0;
            
            /**
             * @brief   Sets the flag indicating whether the window should close the next time
             *          events are polled.
             * 
             * @param   should_close  true if the window should close, false if it should not close
             * 
             * @return  a pointer to the window for chaining
             * 
             * @throw   exception if an error occurs setting whether the window should close
             */
            virtual nonatomic_window_i *set_should_close(bool should_close) = 0;

            /**
             * @brief   Performs any necessary updates for the window. This includes closing the
             *          window if a close was requested. If the window is closed, nothing happens.
             * 
             * @return  true if and only if the window is active (has not been closed)
             * 
             * @throw   exception if an error occurs polling window events
             */
            virtual bool poll_events(void) = 0;
    };
}

#endif

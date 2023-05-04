/**
 * @file    window_i.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for an abstract class that represents an interface specification for a graphical
 *          user interface window. A window is immediately alive (open) upon its object's
 *          construction, however, it may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef WINDOW_I_H_HEADER_GUARD
#define WINDOW_I_H_HEADER_GUARD

#include "../framed_surface_i.hpp"

/**
 * @brief   The default width of a Leaf window.
 */
#define LEAF_WINDOW_DEFAULT_WIDTH (int)600

/**
 * @brief   The default height of a Leaf window.
 */
#define LEAF_WINDOW_DEFAULT_HEIGHT (int)400

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window. A
     *          window is immediately alive (open) upon its object's construction, however, it may
     *          be closed before its object's destruction.
     */
    class window_i : public framed_surface_i
    {
        public:
            /**
             * @brief   Determines whether the window is alive (as opposed to being closed).
             * 
             * @return  true if and only if the window is not closed
             * 
             * @throw   exception if an error occurs determining whether the window is alive
             */
            virtual bool is_alive(void) const = 0;
            
            /**
             * @brief   Informs the window that it should close. Note that this does not guaruntee
             *          an immediate close. Depending on implementation, this may necessitate other
             *          events to perform a close. For instance, some implementations will require
             *          window library events to be polled to recognize that a close should take
             *          place.
             * 
             * @return  true if and only if the window was not already closed (or flagged to close)
             * 
             * @throw   exception if an error occurs closing the window (or indicating that a close
             *          must occur)
             */
            virtual bool close(void) = 0;

            /**
             * @brief   Determines whether the window will automatically enable the close flag when
             *          the user performs a close action on the user interface (This is often in the
             *          form of clicking a red 'x' button on the frame).
             * 
             * @return  true if and only if the window will automatically enable the close flag when
             *          the user performs a close action
             * 
             * @throw   exception if an error occurs determining whether the window will
             *          automatically enable the close flag
             */
            virtual bool is_user_closable(void) const = 0;

            /**
             * @brief   Sets whether the window will automatically enable the close flag when the
             *          user performs a close action on the user interface (This is often in the
             *          form of clicking a red 'x' button on the frame).
             * 
             * @param   is_user_closable    a true value indicates that the window should
             *                              automatically enable the close flag
             * 
             * @return  the previous value of the user closable option prior to setting
             * 
             * @throw   exception if an error occurs setting whether the window will automatically
             *          enable the close flag
             */
            virtual bool set_user_closable(bool is_user_closable) = 0;

            /**
             * @brief   Determines the title of the window. This title is often displayed on the
             *          window's frame.
             * 
             * @return  the title of the window
             * 
             * @throw   exception if an error occurs determining the title of the window
             */
            virtual string title(void) const = 0;

            /**
             * @brief   Sets the title of the window. This title is often displayed on the window's
             *          frame.
             * 
             * @param   title   the title of the window
             * 
             * @return  the previous title prior to setting
             * 
             * @throw   exception if an error occurs setting the title
             */
            virtual string set_title(const string &title) const = 0;
    };
}

#endif

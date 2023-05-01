/**
 * @file    window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents an interface specification for a graphical user
 *          interface window.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef WINDOW_H_HEADER_GUARD
#define WINDOW_H_HEADER_GUARD

/**
 * @brief   The default width of a Leaf window.
 */
#define LEAF_WINDOW_DEFAULT_WIDTH 600

/**
 * @brief   The default height of a Leaf window.
 */
#define LEAF_WINDOW_DEFAULT_HEIGHT 400

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window.
     */
    class window
    {
        /**
         * @brief   Determines whether the window is alive (as opposed to being closed).
         * 
         * @return  true if and only if the window is not closed.
         */
        virtual bool is_alive(void) const noexcept = 0;
        
        /**
         * @brief   Informs the window that it should close. Note that this does not guaruntee an
         *          immediate close. Depending on implementation, this may necessitate other events
         *          to perform a close. For instance, some implementations will require window
         *          library events to be polled to recognize that a close should take place.
         * 
         * @return  true if and only if the window was not already closed
         */
        virtual bool close(void) noexcept = 0;
    };
}

#endif

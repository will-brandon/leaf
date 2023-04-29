/**
 * @file    sdl.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class with static functionality to manage the Simple DirectMedia Layer
 *          library.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_H_HEADER_GUARD
#define SDL_H_HEADER_GUARD

#include <set>
#include <SDL2/SDL.h>
#include <bx/platform.h>
#include "../../utils/inittracker.hpp"
#include "sdlwindow.hpp"

using namespace std;
using namespace utl;

namespace leaf
{
    /**
     * @brief   A class with static functionality to manage the Simple DirectMedia Layer library.
     */
    class sdl
    {
        // The SDL window class must be able to register and deregister windows.
        friend class sdlwindow;

        private:
            /**
             * @brief   An initialization tracker object to track the state of the SDL class.
             */
            static init_tracker f_init_tracker;

            /**
             * @brief   A set of all registered SDL windows.
             */
            static set<sdl_window *> f_windows;

        protected:
            /**
             * @brief   Initializes SDL.
             * 
             * @return  true if and only if SDL was not already initialized.
             * 
             * @throw   runtime_error if SDL fails to initialize.
             */
            static bool init(void);

            /**
             * @brief   Deinitializes SDL.
             * 
             * @return  true if and only if SDL was not already initialized.
             * 
             * @throw   runtime_error if SDL fails to initialize.
             */
            static bool deinit(void);

            /**
             * @brief   Creates an SDL window. The title, position, and size are set to default
             *          values.
             * 
             * @throw   runtime_error if SDL is not initialized or if an error occurs creating the
             *          SDL window
             */
            static sdl_window *create_window(void);

            /**
             * @brief   Creates an SDL window.
             * 
             * @param   title   the title bar content string
             * @param   x       the initial x-position
             * @param   y       the initial y-position
             * @param   width   the initial width
             * @param   height  the initial height
             * 
             * @throw   runtime_error if SDL is not initialized or if an error occurs creating the
             *          SDL window
             */
            static sdl_window *create_window(
                const string &title, int x, int y, int width, int height);
            
        public:
            /**
             * @brief   Determines the name of the operating system the SDL windows resides on.
             * 
             * @return  The name string of the operating system
             */
            inline string native_os_name(void) const noexcept
            {
                // Return the platform name macro from BX.
                return BX_PLATFORM_NAME;
            }

            static size_t window_count(void) noexcept;

            static void poll_events(void) noexcept;
    };
}

#endif

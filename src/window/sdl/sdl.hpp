/**
 * @file    sdl.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class with static functionality to manage the Simple DirectMedia Layer
 *          (SDL) library.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_H_HEADER_GUARD
#define SDL_H_HEADER_GUARD

#include <set>
#include <bx/platform.h>
#include "../../utils/inittracker.hpp"
#include "sdlwindow.hpp"

using namespace std;
using namespace utl;

namespace leaf
{
    /**
     * @brief   A class with static functionality to manage the Simple DirectMedia Layer (SDL)
     *          library.
     */
    class sdl
    {
        private:
            /**
             * @brief   An initialization tracker object to track the state of the SDL class.
             */
            static init_tracker f_init_tracker;

            /**
             * @brief   A set of all registered SDL windows.
             */
            static set<sdl_window *> f_windows;
            
        public:
            /**
             * @brief   Determines whether SDL has been initialized.
             * 
             * @return  true if and only if SDL has been initialized
             */
            static bool did_init(void) noexcept;

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
             */
            static bool deinit(void) noexcept;
            
            /**
             * @brief   Determines the name of the operating system the SDL windows resides on.
             * 
             * @return  the name string of the operating system
             */
            inline static string native_os_name(void) noexcept
            {
                // Return the platform name macro from BX.
                return BX_PLATFORM_NAME;
            }

            /**
             * @brief   Determines the number of SDL windows created by this application.
             * 
             * @return  the number of windows 
             */
            static size_t window_count(void) noexcept;

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
            
            /**
             * @brief   Polls events for all SDL windows. This is necessary to perform windowing
             *          updates such as event listeners.
             * 
             * @throw   runtime_error if SDL is not initialized
             */
            static void poll_events(void);
    };
}

#endif

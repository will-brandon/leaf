/**
 * @file    sdlwindow.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents a graphical user interface window implemented with
 *          SDL.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_WINDOW_H_HEADER_GUARD
#define SDL_WINDOW_H_HEADER_GUARD

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <bx/platform.h>
#include "../nativewindow.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents an interface specification for a graphical user interface window.
     */
    class sdl_window : public native_window
    {
        // The SDL class must be able to create windows.
        friend class sdl;

        private:
            /**
             * @brief   The internal SDL window pointer.
             */
            SDL_Window *m_internal_window;

            /**
             * @brief   System information about the internal window.
             */
            SDL_SysWMinfo m_system_info;

        protected:
            /**
             * @brief   Creates an SDL window. The title, position, and size are set to default
             *          values.
             * 
             * @throw   runtime_error if an error occurs creating the SDL window
             */
            sdl_window(void);

            /**
             * @brief   Creates an SDL window.
             * 
             * @param   title   the title bar content string
             * @param   x       the initial x-position
             * @param   y       the initial y-position
             * @param   width   the initial width
             * @param   height  the initial height
             * 
             * @throw   runtime_error if an error occurs creating the SDL window
             */
            sdl_window(const string &title, int x, int y, int width, int height);

            /**
             * @brief   Destroys the SDL window.
             */
            virtual ~sdl_window() noexcept;

        public:
            /**
             * @brief   An SDL window should not be copied as this copy would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window(const sdl_window &other) noexcept = delete;

            /**
             * @brief   An SDL window should not be moved as this move would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window(sdl_window &&other) noexcept = delete;

            /**
             * @brief   An SDL window should not be copied as this copy would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window &operator=(const sdl_window &other) noexcept = delete;

            /**
             * @brief   An SDL window should not be moved as this move would be shallow. Therefore
             *          this functionality is deleted.
             * 
             * @param   other a separate window object
             */
            sdl_window &operator=(sdl_window &&other) noexcept = delete;

            /**
             * @brief   Determines the name of the operating system the window resides on.
             * 
             * @return  The name string of the operating system
             */
            inline string native_os_name(void) const noexcept override
            {
                // Return the platform name macro from BX.
                return BX_PLATFORM_NAME;
            }

            /**
             * @brief   Determines the operating system native handle of the window.
             * 
             * @return  The native window handle in the form of a pointer
             */
            void *native_handle(void) const noexcept override;
    };
}

#endif

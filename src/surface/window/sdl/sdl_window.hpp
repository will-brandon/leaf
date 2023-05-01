/**
 * @file    sdl_window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    April 28, 2023
 * 
 * @brief   Header for a class that represents a graphical user interface window implemented with
 *          SDL. A window is immediately alive (open) upon its object's construction, however, it
 *          may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_WINDOW_H_HEADER_GUARD
#define SDL_WINDOW_H_HEADER_GUARD

#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include <bx/platform.h>
#include "../../native_surface_i.hpp"
#include "../nonatomic_window_i.hpp"
#include "sdl_types.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a graphical user interface window implemented with SDL. A window is
     *          immediately alive (open) upon its object's construction, however, it may be closed
     *          before its object's destruction.
     */
    class sdl_window : public native_surface_i, public nonatomic_window_i
    {
        // The SDL manager class must be able to create and destroy windows.
        friend class sdl;

        private:
            /**
             * @brief   Denotes whether the window is alive (open) or dead (closed) represented by
             *          the values true or false respectively.
             */
            bool m_is_alive;

            /**
             * @brief   Denotes whether the window should close the next time events are polled.
             */
            bool m_should_close;

            /**
             * @brief   The internal SDL window pointer.
             */
            SDL_Window *m_internal_window;

            /**
             * @brief   Internal platform-dependent system information about the window.
             */
            SDL_SysWMinfo m_system_info;

            /**
             * @brief   Native platform-dependent data about the window's display surface.
             */
            native_surface_data_t m_native_data;

            /**
             * @brief   Creates the native data for the window's display surface.
             * 
             * @throw   runtime_error if the operating system is not supported
             */
            void init_natives(void);

        protected:
            /**
             * @brief   Creates an SDL window. The title, position, and size are set to default
             *          values. When the window is created it is immediately active. Assuming that
             *          it is visible and SDL events are polled, it will begin displaying upon
             *          creation.
             * 
             * @throw   runtime_error if an error occurs creating the SDL window
             */
            sdl_window(void);

            /**
             * @brief   Creates an SDL window. When the window is created it is immediately active.
             *          Assuming that it is visible and SDL events are polled, it will begin
             *          displaying upon creation.
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
             * @brief   Determines the version of SDL being used for the window.
             * 
             * @return  a structure containing components comprising the version of SDL being used
             */
            inline sdl_version_t sdl_version(void) const noexcept
            {
                // Create a version structure.
                sdl_version_t version;

                // Copy the SDL version information into the structure.
                SDL_VERSION(&version)

                // Return the version structure.
                return version;
            }

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
             * @brief   Returns native platform-dependent data about the window. A null display type
             *          pointer is acceptable on some systems. However, a null window handle pointer
             *          indicates that the operating system is not supported.
             * 
             * @return  a structure of native window data
             */
            native_window_data_t native_data(void) const noexcept override;
    };
}

#endif

/**
 * @file    managed_native_window.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 4, 2023
 * 
 * @brief   Header for an abstract class that represents a graphical user interface window that is
 *          managed by a window manager and has a native handle for the underlying operating system.
 *          A window is immediately alive (open) upon its object's construction, however, it may be
 *          closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef MANAGED_NATIVE_WINDOW_H_HEADER_GUARD
#define MANAGED_NATIVE_WINDOW_H_HEADER_GUARD

#include "managed_window.hpp"

using namespace std;

namespace leaf
{
    /**
     * @brief   Represents a graphical user interface window that is managed by a window manager and
     *          has a native handle for the underlying operating system. A window is immediately
     *          alive (open) upon its object's construction, however, it may be closed before its
     *          object's destruction.
     */
    class managed_native_window : public managed_window, public native_surface_i
    {
        private:
            /**
             * @brief   Native platform-dependent data about the window's display surface.
             */
            native_surface_data_t m_native_data;

        protected:
            /**
             * @brief   Creates a managed window. The title, position, and size are set to default
             *          values. When the window is created it is immediately alive. Assuming that it
             *          is visible and window manager events are polled, it will begin displaying
             *          upon creation.
             * 
             * @throw   runtime_error if an error occurs creating the window
             */
            managed_native_window(void);

            /**
             * @brief   Destructs the window object.
             * 
             * @note    The default implementation in maintained because no resources need
             *          deallocation. The declaration is only explicit so that the destructor can be
             *          marked virtual.
             */
            virtual ~managed_native_window() noexcept = default;

            /**
             * @brief   Creates the native data for the window's display surface.
             * 
             * @throw   runtime_error if the operating system is not supported
             */
            virtual void init_natives(void) = 0;

        public:
            /**
             * @brief   Determines the name of the operating system the window resides on.
             * 
             * @return  The name string of the operating system
             */
            virtual string native_os_name(void) const noexcept override

            /**
             * @brief   Returns native platform-dependent data about the window's display surface.
             *          A null display type pointer is acceptable on some systems. However, a null
             *          handle pointer indicates that the operating system is not supported.
             * 
             * @return  a structure of native surface data
             */
            native_surface_data_t native_data(void) const noexcept override;
    };
}

#endif

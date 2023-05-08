/**
 * @file    sdl.hpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 8, 2023
 * 
 * @brief   Header for a class that represents the Simple DirectMedia Layer (SDL) window library
 *          manager. The class creates a singleton object, i.e. only one window manager object can
 *          be created.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef SDL_H_HEADER_GUARD
#define SDL_H_HEADER_GUARD

// The class must be forward declared because there are circular includes between the SDL window
// manager and SDL window classes.
namespace leaf
{
    class sdl;
}

#include <set>
#include <bx/platform.h>
#include "../../../utils/release_types.hpp"
#include "../window_manager.hpp"
#include "sdl_window.hpp"

namespace leaf
{
    /**
     * @brief   Represents the Simple DirectMedia Layer (SDL) window library manager. The class
     *          creates a singleton object, i.e. only one window manager object can be created.
     */
    class sdl : public window_manager
    {
        // SDL windows must be able to access hidden functionality of the SDL window manager.
        friend class sdl_window;

        public:
            /**
             * @brief   One single instance of the SDL window manager will be created. This instance
             *          should be used externally to make all API calls.
             */
            static sdl instance;

        protected:
            /**
             * @brief   Creates a new instance of the SDL library and initializes SDL. Only one SDL
             *          instance object can exist per program runtime.
             * 
             * @throw   runtime_error if SDL failed to initialize or if an SDL object has already
             *          been created in the program environment
             */
            sdl(void);

            /**
             * @brief Deinitializes SDL and destroys the SDL instance object.
             */
            virtual ~sdl() noexcept;

        public:
            /**
             * @brief   Performs updates on the SDL window manager. This will poll the events of
             *          each individual living managed window as well as perform any necessary SDL
             *          calls.
             * 
             * @return  true if and only if at least one living window is under management
             */
            virtual bool poll_events(void) noexcept override;

            /**
             * @brief   Determines the version of SDL being used.
             * 
             * @return  a structure containing components comprising the version of SDL being used
             */
            inline utl::release_version_t sdl_version(void) const noexcept
            {
                // Create an SDL version structure.
                SDL_version version;

                // Copy the SDL version information into the structure.
                SDL_VERSION(&version)

                // Return a release structure copied from the SDL version structure.
                return {version.major, version.minor, version.patch};
            }
    };
}

#endif

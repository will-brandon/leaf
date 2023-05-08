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

#include <set>
#include <bx/platform.h>
#include "../../../utils/release_types.hpp"
#include "../window_manager.hpp"

namespace leaf
{
    /**
     * @brief   Represents the Simple DirectMedia Layer (SDL) window library manager. The class
     *          creates a singleton object, i.e. only one window manager object can be created.
     */
    class sdl : public window_manager
    {
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

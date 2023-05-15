/// 
/// @file       sdl_window_event_manager.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 14, 2023
/// 
/// @brief      
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_SDL_WINDOW_EVENT_MANAGER_HEADER_GUARD
#define LEAF_SRC_SDL_WINDOW_EVENT_MANAGER_HEADER_GUARD

#include "../window_event_manager.hpp"

namespace leaf
{
    /// 
    /// @brief  
    /// 
    class sdl_window_event_manager : public window_event_manager
    {
        /// 
        /// @brief      Handles an SDL window event and notifies the proper handler of the event.
        ///             Events that are not window related will be ignored.
        /// 
        /// @param      event   the SDL event
        /// 
        void handle_sdl_event(const SDL_Event &event) noexcept;
    };
}

#endif

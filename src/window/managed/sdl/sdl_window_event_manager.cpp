/// 
/// @file       sdl_window_event_manager.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 14, 2023
/// 
/// @brief      
/// 
/// @copyright  Copyright (c) 2023
/// 

#include <SDL3/SDL_events.h>
#include "sdl_window_event_manager.hpp"

namespace leaf
{
    void sdl_window_event_manager::handle_sdl_event(const SDL_Event &event) noexcept
    {
        // Proccess the event based on its type. This changed in SDL3. In SDL2, the event structure
        // was heirarchical and 2 nested conditional switches were necessary. Now the structure is
        // more conveniently flat.
        switch (event.type)
        {
            // Called when the user requests a close (clicks the close button on the frame).
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:

                // If the window is user-closable set the close flag to indicate that a close is
                // necessary.
                if (is_user_closable())
                {
                    this->close();
                }

                // Notify the event manager of the user-requested close.
                user_requested_close();

                break;

            // Called when the window is resized. This can either be user-initiated or automatic.
            case SDL_EVENT_WINDOW_RESIZED:

                // Notify the event manager of the resize.
                resized(this->bounds());

                break;
            
            // Called when the window is moved. This can either be user-initiated or automatic.
            case SDL_EVENT_WINDOW_MOVED:

                // Notify the event manager of the move.
                moved(this->pos(), this->frame_pos());

                break;

            case SDL_EVENT_WINDOW_SHOWN:
        }
    }
}

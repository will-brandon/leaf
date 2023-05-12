/// 
/// @file       window_event_handler_i.hpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       May 12, 2023
/// 
/// @brief      Header for an abstract class that represents an interface specification for a
///             keyboard event handler. A keyboard event handler will contain functionality that
///             will be triggered by a keyboard listener when the handler object is subscribed to
///             the listener.
/// 
/// @copyright  Copyright (c) 2023
/// 

#ifndef LEAF_SRC_KEY_EVENT_HANDLER_I_HEADER_GUARD
#define LEAF_SRC_KEY_EVENT_HANDLER_I_HEADER_GUARD

#include "event_handler_i.hpp"
#include "../graphics/graphics_types.hpp"

namespace leaf
{
    /// 
    /// @brief  Represents an interface specification for a keyboard event handler. A keyboard event
    ///         handler will contain functionality that will be triggered by a keyboard listener
    ///         when the handler object is subscribed to the listener.
    /// 
    class key_event_handler_i : virtual public event_handler_i
    {
        //public:
            //virtual void keydown(void)
    };
}

#endif

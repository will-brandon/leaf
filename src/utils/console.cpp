/// 
/// @file       console.cpp
/// @author     Will Brandon (brandon.w@northeastern.edu)
/// @date       February 6, 2023
/// 
/// @brief      Implementation for a class with static functionality to interact with the terminal
///             console.
/// 
/// @copyright  Copyright (c) 2023
/// 

#include "console.hpp"

namespace utl
{
    // By default ANSI style is enabled.
    bool console::f_ansi_style_enabled(true);

    bool console::ansi_style_enabled(void) noexcept
    {
        // Return whether ANSI style is enabled.
        return f_ansi_style_enabled;
    }

    void console::set_ansi_style_enabled(bool enabled) noexcept
    {
        // Set whether ANSI style is enabled.
        f_ansi_style_enabled = enabled;
    }
}
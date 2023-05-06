/**
 * @file    sdl_window.cpp
 * @author  Will Brandon (brandon.w@northeastern.edu)
 * @date    May 5, 2023
 * 
 * @brief   Implementation for a class that represents a graphical user interface window implemented
 *          with SDL. A window is immediately alive (open) upon its object's construction, however,
 *          it may be closed before its object's destruction.
 *
 * @copyright Copyright (c) 2023
 */

#include "sdl_window.hpp"

using namespace std;

namespace leaf
{
    void sdl_window::init_natives(void)
    {

    }

    sdl_window::sdl_window(void)
    {

    }

    sdl_window::sdl_window(const string &title, int x, int y, int width, int height)
    {

    }

    sdl_window::~sdl_window() noexcept
    {

    }

    bool sdl_window::destroy(void) noexcept
    {

    }

    px_t sdl_window::width(void) const noexcept
    {
        
    }

    px_t sdl_window::height(void) const noexcept
    {

    }

    px_t set_width(px_t width) noexcept
    {

    }

    px_t set_height(px_t height) noexcept
    {

    }

    void sdl_window::set_size(px_t width, px_t height) noexcept
    {

    }

    bool sdl_window::is_visible(void) const noexcept
    {

    }

    bool sdl_window::set_visible(bool is_visible) noexcept
    {

    }

    px_t sdl_window:: x(void) const noexcept
    {

    }

    px_t sdl_window::y(void) const noexcept
    {

    }

    px_t sdl_window::set_x(px_t x) noexcept
    {

    }

    px_t sdl_window::set_y(px_t y) noexcept
    {

    }

    void sdl_window::set_position(px_t x, px_t y) noexcept
    {

    }
    
    bool sdl_window::is_visible(void) const noexcept
    {

    }

    bool sdl_window::set_visible(bool is_visible) noexcept
    {

    }

    px_t sdl_window::x(void) const noexcept
    {

    }

    px_t sdl_window::y(void) const noexcept
    {

    }

    px_t sdl_window::set_x(px_t x) noexcept
    {

    }

    px_t sdl_window::set_y(px_t y) noexcept
    {

    }

    void sdl_window::set_position(px_t x, px_t y) noexcept
    {

    }

    bool sdl_window::is_user_movable(void) const noexcept
    {

    }
            
    bool sdl_window::set_user_movable(bool is_user_movable) noexcept
    {

    }

    bool sdl_window::is_user_resizable(void) const noexcept
    {

    }

    bool sdl_window::set_user_resizable(bool is_user_resizable) noexcept
    {

    }

    string sdl_window::title(void) const noexcept
    {

    }

    string sdl_window::set_title(const string &title) const noexcept
    {

    }

    bool sdl_window::should_close(void) const noexcept
    {

    }

    bool sdl_window::poll_events(void) noexcept
    {

    }

    string sdl_window::native_os_name(void) const noexcept
    {

    }

    native_surface_data_t sdl_window::native_data(void) const noexcept
    {

    }
}

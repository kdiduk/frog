//! \file       sdl_window.cpp
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       28 March, 2021
//! \copyright  MIT License

#include "sdl_window.h"

#include <sstream>
#include <stdexcept>


namespace frog {

    const std::string sdl_window::window_title = "Forester";

    sdl_window::sdl_window()
        : m_window{make_window_ptr()},
          m_renderer(new_sdl_renderer(), {680, 360})
    {

    }

    sdl_window::~sdl_window() = default;

    sdl_renderer& sdl_window::renderer()
    {
        return m_renderer;
    }

    sdl_window::window_ptr sdl_window::make_window_ptr() const
    {
        auto window = SDL_CreateWindow(
                window_title.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                default_width,
                default_height,
                0);
        if (!window) {
            std::stringstream msg;
            msg << "Failed to create SDL window: " << SDL_GetError();
            throw std::runtime_error(msg.str());
        }

        return window_ptr(window, &SDL_DestroyWindow);
    }

    SDL_Renderer* sdl_window::new_sdl_renderer() const
    {
        auto renderer = SDL_CreateRenderer(m_window.get(), -1, 0);
        if (!renderer) {
            std::stringstream msg;
            msg << "Failed to create SDL renderer: " << SDL_GetError();
            throw std::runtime_error(msg.str());
        }

        return renderer;
    }

} // namespace frog

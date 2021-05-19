//! \file       sdl_renderer.cpp
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       2 April, 2021
//! \copyright  MIT License

#include "sdl_renderer.h"

#include <stdexcept>

#include "frog/texture.h"
#include "texture_id.h"


namespace frog {

    sdl_renderer::sdl_renderer(SDL_Renderer* rr, vec<int> res)
        : m_renderer(rr),
          m_resolution{std::move(res)}
    {
        if (!rr) {
            throw std::invalid_argument("SDL_Renderer object must not be null");
        }

        SDL_SetRenderDrawColor(m_renderer.get(),
                0x00,
                0x00,
                0x00,
                0xFF);
        SDL_RenderSetLogicalSize(m_renderer.get(),
                m_resolution.x,
                m_resolution.y);
    }

    sdl_renderer::~sdl_renderer() = default;

    vec<int> sdl_renderer::resolution() const
    {
        return m_resolution;
    }

    void sdl_renderer::clear_target() const
    {
        SDL_RenderClear(m_renderer.get());
    }

    void sdl_renderer::render_texture(const texture& tx,
            const rect& dest_rect) const
    {
        SDL_Rect dest{
            dest_rect.position().x,
            dest_rect.position().y,
            dest_rect.size().x,
            dest_rect.size().y };

        SDL_RenderCopy(m_renderer.get(), tx.id(), nullptr, &dest);
    }

    void sdl_renderer::present() const
    {
        SDL_RenderPresent(m_renderer.get());
    }

    sdl_renderer::operator SDL_Renderer*() const
    {
        return const_cast<sdl_renderer*>(this)->m_renderer.get();
    }

} // namespace frog

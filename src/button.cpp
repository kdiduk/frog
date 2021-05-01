//! \file       button.cpp
//! \date       21 April, 2021
//! \copyright  MIT License

#include "frog/button.h"

#include "frog/texture.h"
#include "frog/rect.h"
#include "renderer.h"


namespace frog {

    button::button(std::shared_ptr<texture> tx, vec<int> pos)
        : m_texture{std::move(tx)},
          m_rect{std::move(pos), {m_texture->width(), m_texture->height()}}
    {
    }

    button::button(std::shared_ptr<texture> tx, vec<int> pos, vec<int> size)
        : m_texture{std::move(tx)},
          m_rect{std::move(pos), std::move(size)}
    {

    }

    void button::listen_press(std::function<void()> listener)
    {
        m_listeners.push_back(std::move(listener));
    }

    void button::remove_listeners()
    {
        m_listeners.clear();
    }

    void button::render(const renderer& rr) const
    {
        rr.render_texture(*m_texture, m_rect);
    }

    void button::finger_down_event(vec<int> pos)
    {
        if (m_rect.contains(pos)) {
            m_pressed = true;
        }
    }

    void button::finger_up_event(vec<int> pos)
    {
        m_pressed = false;
        if (m_rect.contains(pos)) {
            for (auto lsr: m_listeners) {
                lsr();
            }
        }
    }

} // namespace frog

// EOF

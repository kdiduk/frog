//! \file       sprite.cpp
//! \date       9 April, 2021
//! \copyright  MIT License

#include "frog/sprite.h"

#include "frog/rect.h"
#include "frog/texture.h"
#include "renderer.h"


namespace frog {

    sprite::sprite(std::shared_ptr<texture> tx,
            vec<int> pos,
            vec<int> scale)
        : m_texture{tx},
          m_position{std::move(pos)},
          m_scale{std::move(scale)}
    {
    }

    vec<int>& sprite::position()
    {
        return m_position;
    }

    void sprite::render(const renderer& rr) const
    {
        vec<int> size{
                m_texture->width() * m_scale.x,
                m_texture->height() * m_scale.y};
        rr.render_texture(*m_texture, rect(m_position, size));
    }

} // namespace frog

// EOF

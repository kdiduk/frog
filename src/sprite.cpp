//! \file       sprite.cpp
//! \date       9 April, 2021
//! \copyright  MIT License

#include "frog/sprite.h"

#include "frog/rect.h"
#include "frog/texture.h"
#include "frog/vec_operations.h"
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

    const vec<int>& sprite::position() const
    {
        return m_position;
    }

    vec<int> sprite::size() const
    {
        return vec<int>{
                m_texture->width() * m_scale.x,
                m_texture->height() * m_scale.y};
    }

    void sprite::move_by(const vec<int>& dv)
    {
        m_position += dv;
    }

    void sprite::render(const renderer& rr) const
    {
        rr.render_texture(*m_texture, rect(m_position, size()));
    }

} // namespace frog

// EOF

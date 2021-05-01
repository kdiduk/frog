//! \file       rect.cpp
//! \date       15 April, 2021
//! \copyright  MIT License

#include "frog/rect.h"

#include <utility>

namespace frog {

    rect::rect(vec<int> pos, vec<int> sz)
        : m_position(std::move(pos)), m_size(std::move(sz))
    {
    }

    rect::rect(int x, int y, int w, int h)
        : m_position{x, y}, m_size{w, h}
    {
    }

    const vec<int>& rect::position() const
    {
        return m_position;
    }

    vec<int>& rect::position()
    {
        return m_position;
    }

    const vec<int>& rect::size() const
    {
        return m_size;
    }

    vec<int>& rect::size()
    {
        return m_size;
    }

    bool rect::contains(const vec<int>& pt) const
    {
        int x1 = m_position.x;
        int x2 = x1 + m_size.x;
        int y1 = m_position.y;
        int y2 = y1 + m_size.y;

        return (pt.x >= x1 && pt.x <= x2
             && pt.y >= y1 && pt.y <= y2);
    }

} // namespace frog

// EOF

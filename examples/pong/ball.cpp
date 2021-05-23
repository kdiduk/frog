//! \file       ball.cpp
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       21 May, 2021
//! \copyright  MIT License

#include "ball.h"

#include "frog/program.h"
#include "frog/texture.h"
#include "frog/vec_operations.h"

namespace pong {
    ball::ball()
    {
        auto tx = std::make_shared<frog::texture>("ball.png");
        auto pos = frog::program::instance()->window_size() / 2;
        m_sprite = std::make_shared<frog::sprite>(tx, pos);
        add_child(m_sprite);

        m_speed = { 8, 7 };
    }

    frog::vec<int> ball::position() const
    {
        return m_sprite->position();
    }

    void ball::update(unsigned delta)
    {
        m_sprite->move_by(m_speed);

        if (ball_hits_top() || ball_hits_bottom()) {
            m_speed.y = -m_speed.y;
        }
        else if (ball_hits_left() || ball_hits_right()) {
            m_speed.x = -m_speed.x;
        }
    }

    bool ball::ball_hits_top() const
    {
        return (position().y <= 0);
    }

    bool ball::ball_hits_bottom() const
    {
        return (position().y + m_sprite->size().y
                >= frog::program::instance()->window_size().y);
    }

    bool ball::ball_hits_left() const
    {
        return (position().x <= 0);
    }

    bool ball::ball_hits_right() const
    {
        return (position().x + m_sprite->size().x
                >= frog::program::instance()->window_size().x);
    }

} // namespace

// EOF

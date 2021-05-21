//! \file       game_scene.cpp
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       05 May, 2021
//! \copyright  MIT License

#include "game_scene.h"

#include "frog/program.h"
#include "frog/texture.h"
#include "frog/vec_operations.h"

namespace pong {

    game_scene::game_scene()
    {
        auto tx = std::make_shared<frog::texture>("ball.png");
        auto pos = frog::program::instance()->window_size() / 2;
        m_ball_sprite = std::make_shared<frog::sprite>(tx, pos);
        add_child(m_ball_sprite);

        m_ball_speed_vector = { 8, 7 };
    }

    void game_scene::update(unsigned delta)
    {
        m_ball_sprite->move_by(m_ball_speed_vector);

        if (ball_hits_top() || ball_hits_bottom()) {
            m_ball_speed_vector.y = -m_ball_speed_vector.y;
        }
        else if (ball_hits_left() || ball_hits_right()) {
            m_ball_speed_vector.x = -m_ball_speed_vector.x;
        }
    }

    bool game_scene::ball_hits_top() const
    {
        return (m_ball_sprite->position().y <= 0);
    }

    bool game_scene::ball_hits_bottom() const
    {
        return (m_ball_sprite->position().y + m_ball_sprite->size().y
                >= frog::program::instance()->window_size().y);
    }

    bool game_scene::ball_hits_left() const
    {
        return (m_ball_sprite->position().x <= 0);
    }

    bool game_scene::ball_hits_right() const
    {
        return (m_ball_sprite->position().x + m_ball_sprite->size().x
                >= frog::program::instance()->window_size().x);
    }
}

// EOF

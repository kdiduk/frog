//! \file       game_scene.cpp
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       05 May, 2021
//! \copyright  MIT License

#include "game_scene.h"

#include "frog/texture.h"

namespace pong {

    game_scene::game_scene()
    {
        auto tx = std::make_shared<frog::texture>("ball.png");
        m_ball_sprite = std::make_shared<frog::sprite>(tx);

        add_child(m_ball_sprite);
    }
    
    void game_scene::update(unsigned delta)
    {
    }
}

// EOF

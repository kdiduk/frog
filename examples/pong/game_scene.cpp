//! \file       game_scene.cpp
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       05 May, 2021
//! \copyright  MIT License

#include "game_scene.h"

namespace pong {

    game_scene::game_scene()
    {
        m_ball = std::make_shared<ball>();
        add_child(m_ball);
    }

    void game_scene::update(unsigned delta)
    {
    }

}

// EOF

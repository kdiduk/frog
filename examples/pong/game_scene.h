//! \file       game_scene.h
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       05 May, 2021
//! \copyright  MIT License

#ifndef GAME_SCENE_H_BEC674A4_8806_4530_9465_4D4A8D3E8F11
#define GAME_SCENE_H_BEC674A4_8806_4530_9465_4D4A8D3E8F11

#include <memory>

#include "frog/scene.h"
#include "ball.h"

namespace pong {
    class game_scene
        : public frog::scene
    {
    public:
        explicit game_scene();

    protected:

        void update(unsigned delta) override;

    private:
        std::shared_ptr<ball> m_ball;
    };
}

#endif // GAME_SCENE_H_BEC674A4_8806_4530_9465_4D4A8D3E8F11

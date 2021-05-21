//! \file       game_scene.h
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       05 May, 2021
//! \copyright  MIT License

#ifndef GAME_SCENE_H_BEC674A4_8806_4530_9465_4D4A8D3E8F11
#define GAME_SCENE_H_BEC674A4_8806_4530_9465_4D4A8D3E8F11

#include <memory>

#include "frog/scene.h"
#include "frog/sprite.h"

namespace pong {
    class game_scene
        : public frog::scene
    {
    public:
        explicit game_scene();

    protected:

        void update(unsigned delta) override;

    private:

        bool ball_hits_top() const;
        bool ball_hits_bottom() const;
        bool ball_hits_left() const;
        bool ball_hits_right() const;

        std::shared_ptr<frog::sprite> m_ball_sprite;
        frog::vec<int> m_ball_speed_vector;
    };
}

#endif // GAME_SCENE_H_BEC674A4_8806_4530_9465_4D4A8D3E8F11

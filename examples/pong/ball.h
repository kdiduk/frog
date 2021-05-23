//! \file       ball.h
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       21 May, 2021
//! \copyright  MIT License

#ifndef BALL_H_61AB9560_6F63_4705_B3AB_D7CE19BADB4A
#define BALL_H_61AB9560_6F63_4705_B3AB_D7CE19BADB4A

#include "frog/scene.h"
#include "frog/sprite.h"
#include "frog/vec.h"

namespace pong {
    class ball : public frog::scene {
    public:
        explicit ball();

        frog::vec<int> position() const;

    protected:
        void update(unsigned delta) override;

    private:

        bool ball_hits_top() const;
        bool ball_hits_bottom() const;
        bool ball_hits_left() const;
        bool ball_hits_right() const;

        std::shared_ptr<frog::sprite> m_sprite;
        frog::vec<int> m_speed;
    };
} // namespace

#endif // BALL_H_61AB9560_6F63_4705_B3AB_D7CE19BADB4A

// EOF

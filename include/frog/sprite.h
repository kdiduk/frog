//! \file       sprite.h
//! \date       9 April, 2021
//! \copyright  MIT License

#ifndef SPRITE_H_A911D9A0_AA1C_4E31_93C0_2747497E1003
#define SPRITE_H_A911D9A0_AA1C_4E31_93C0_2747497E1003

#include <memory>

#include "frog/node.h"
#include "frog/vec.h"


namespace frog {

    class renderer;
    class texture;

    //! \brief Sprite class renders a texture.
    //!
    //! \details A sprite has a texture (that can be shared between different
    //! sprites) and geometry properties like position, scale.
    //!
    class sprite : public node {
    public:
        explicit sprite(std::shared_ptr<texture> tx,
                vec<int> pos = {0, 0},
                vec<int> scale = {1, 1});

        vec<int>& position();

    protected:
        //! \brief Renders the sprite using the specified renderer.
        void render(const renderer& rr) const override;

    private:
        std::shared_ptr<texture> m_texture;
        vec<int> m_position;
        vec<int> m_scale;
    };
} // namespace frog

#endif // SPRITE_H_A911D9A0_AA1C_4E31_93C0_2747497E1003

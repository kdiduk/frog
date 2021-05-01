//! \file       renderer.h
//! \date       14 April, 2021
//! \copyright  MIT License

#ifndef RENDERER_H_4349DAFA_1029_434C_8CF3_3F251F23C859
#define RENDERER_H_4349DAFA_1029_434C_8CF3_3F251F23C859

#include "frog/rect.h"
#include "frog/vec.h"


namespace frog {

    class texture;

    class renderer {
    public:
        virtual vec<short> resolution() const = 0;
        virtual void clear_target() const = 0;
        virtual void render_texture(
                const texture& tx, const rect& dst_rect) const = 0;
        virtual void present() const = 0;


        // The Rule of Five.
        virtual ~renderer() = default;
        renderer(const renderer&) = delete;
        renderer(renderer&&) = delete;
        renderer& operator=(const renderer&) = delete;
        renderer& operator=(renderer&&) = delete;

    protected:
        renderer() = default;
    };
} // namespace frog

#endif // RENDERER_H_4349DAFA_1029_434C_8CF3_3F251F23C859

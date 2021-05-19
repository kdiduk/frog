//! \file       camera_renderer.h
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       14 April, 2021
//! \copyright  MIT License

#ifndef CAMERA_RENDERER_H_ED8DDFDB_75FB_4225_976C_17DA0D0A9335
#define CAMERA_RENDERER_H_ED8DDFDB_75FB_4225_976C_17DA0D0A9335

#include "renderer.h"

namespace frog {

    class camera;

    //! \brief Decorates renderer with a camera.
    //!
    class camera_renderer : public renderer {
    public:
        camera_renderer(const renderer& rr, const camera& cam);

        vec<int> resolution() const override;
        void clear_target() const override;
        void render_texture(const texture& tx,
                const rect& dst_rect) const override;
        void present() const override;

    private:
        const renderer& m_renderer;
        const camera& m_camera;
    };
} // namespace frog

#endif // CAMERA_RENDERER_H_ED8DDFDB_75FB_4225_976C_17DA0D0A9335

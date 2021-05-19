//! \file       camera_renderer.cpp
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       14 April, 2021
//! \copyright  MIT License

#include "camera_renderer.h"

#include "frog/camera.h"


namespace frog {

    camera_renderer::camera_renderer(const renderer& rr, const camera& cam)
        : m_renderer(rr), m_camera(cam)
    {

    }

    vec<int> camera_renderer::resolution() const
    {
        return m_renderer.resolution();
    }

    void camera_renderer::clear_target() const
    {
        m_renderer.clear_target();
    }

    void camera_renderer::render_texture(const texture& tx,
                        const rect& dst_rect) const
    {
        rect dst(dst_rect);
        dst.position().x -= m_camera.position().x;
        dst.position().y -= m_camera.position().y;

        m_renderer.render_texture(tx, dst);
    }

    void camera_renderer::present() const
    {
        m_renderer.present();
    }

} // namespace frog

// EOF

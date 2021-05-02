//! \file       scene.cpp
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       10 April, 2021
//! \copyright  MIT License

#include "frog/scene.h"

#include <memory>
#include <vector>

#include "frog/node.h"
#include "camera_renderer.h"


namespace frog {

    scene::scene()
    {
    }

    scene::~scene() = default;

    std::shared_ptr<camera> scene::camera()
    {
        return m_camera;
    }

    void scene::set_camera(std::shared_ptr<class camera> cam)
    {
        m_camera = cam;
    }

    void scene::update_(unsigned delta)
    {
        update(delta);

        for (const auto& scene: m_child_scenes) {
            scene->update_(delta);
        }
    }

    void scene::render_(const renderer& rr)
    {
        if (m_camera) {
            camera_renderer r(rr, *m_camera);
            render_child_nodes(r);
        }
        else {
            render_child_nodes(rr);
        }
        render_child_scenes(rr);
    }

    void scene::handle_finger_down_(vec<int> pos)
    {
        for (auto& node : m_child_nodes) {
            node->finger_down_event(pos);
        }

        for (auto& child : m_child_scenes) {
            child->handle_finger_down_(pos);
        }

        finger_down_event(pos);
    }

    void scene::handle_finger_up_(vec<int> pos)
    {
        for (auto& node : m_child_nodes) {
            node->finger_up_event(pos);
        }

        for (auto& child : m_child_scenes) {
            child->handle_finger_up_(pos);
        }

        finger_up_event(pos);
    }

    void scene::update([[maybe_unused]] unsigned delta)
    {
    }

    void scene::finger_down_event([[maybe_unused]] vec<int> pos)
    {
    }

    void scene::finger_up_event([[maybe_unused]] vec<int> pos)
    {
    }

    void scene::add_child(std::shared_ptr<node> child_node)
    {
        m_child_nodes.push_back(child_node);
    }

    void scene::add_child(std::shared_ptr<scene> child_scene)
    {
        m_child_scenes.push_back(child_scene);
    }

    void scene::render_child_nodes(const renderer& rr)
    {
        for (const auto& node : m_child_nodes) {
            node->render(rr);
        }
    }

    void scene::render_child_scenes(const renderer& rr)
    {
        for (const auto& scene: m_child_scenes) {
            scene->render_(rr);
        }
    }

} // namespace frog

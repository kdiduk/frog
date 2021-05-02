//! \file       scene.h
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       7 April, 2021
//! \copyright  MIT License

#ifndef SCENE_H_84364F4F_E5D1_456D_B0F2_4D812F736F68
#define SCENE_H_84364F4F_E5D1_456D_B0F2_4D812F736F68

#include <memory>
#include <vector>

#include "frog/vec.h"


namespace frog {

    class camera;
    class node;
    class renderer;

    class scene {
    public:
        scene();
        virtual ~scene();

        scene(const scene&) = delete;
        scene(scene&&) = delete;
        scene& operator=(const scene&) = delete;
        scene& operator=(scene&&) = delete;

        std::shared_ptr<class camera> camera();
        void set_camera(std::shared_ptr<class camera> cam);

        //! \brief Internal method called in the main game loop.
        //!
        //! \see on_update()
        //!
        void update_(unsigned delta);

        //! \brief Internal method called in the main game loop.
        //!
        //! \note Since `renderer` is an internal class and it's not
        //! defined in any public headers, this function can be only
        //! called by internal code.
        void render_(const renderer& rr);

        void handle_finger_down_(vec<int> pos);
        void handle_finger_up_(vec<int> pos);

    protected:

        virtual void update(unsigned delta);

        virtual void finger_down_event(vec<int> pos);
        virtual void finger_up_event(vec<int> pos);

        void add_child(std::shared_ptr<node> child_node);
        void add_child(std::shared_ptr<scene> child_scene);

    private:
        void render_child_nodes(const renderer& rr);
        void render_child_scenes(const renderer& rr);

        std::vector<std::shared_ptr<node>> m_child_nodes;
        std::vector<std::shared_ptr<scene>> m_child_scenes;
        std::shared_ptr<class camera> m_camera;
    }; // class scene

} // namespace frog

#endif // SCENE_H_84364F4F_E5D1_456D_B0F2_4D812F736F68

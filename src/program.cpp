//! \file       program.cpp
//! \brief      Contains implementation of `program` class.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       27 March, 2021
//! \copyright  MIT License

#include "frog/program.h"

#include <cassert>
#include <stdexcept>
#include <utility>

#include <SDL.h>

#include "frog/scene.h"
#include "program_impl.h"


namespace frog {

    program* program::m_instance = nullptr;

    program::program([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
        : m_pimpl{ std::make_unique<impl>() }
    {
        if (m_instance) {
            throw std::runtime_error("Instance of `program` class already exists");
        }
        m_instance = this;
    }

    program::~program()
    {
        m_instance = nullptr;
    }

    int program::run(std::shared_ptr<scene> s)
    {
        if (m_pimpl->run_already_called) {
            throw std::runtime_error("Recursive call of `program::run()`");
        }
        m_pimpl->run_already_called = true;

        change_scene(std::move(s));

        while (!m_pimpl->quit) {
            m_pimpl->process_events();

            m_pimpl->current_scene->update_(40);

            renderer().clear_target();
            m_pimpl->current_scene->render_(renderer());
            renderer().present();

            SDL_Delay(40);
        }

        m_pimpl->run_already_called = false;
        return 0;
    }

    const renderer& program::renderer() const
    {
        return m_pimpl->window.renderer();
    }

    void program::change_scene(std::shared_ptr<scene> s)
    {
        m_pimpl->current_scene = std::move(s);
    }

    vec<short> program::window_size() const
    {
        return renderer().resolution();
    }

    program* program::instance()
    {
        return m_instance;
    }

} // namespace frog

// EOF

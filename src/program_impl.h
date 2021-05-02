//! \file       program_impl.h
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       27 March, 2021
//! \copyright  MIT License

#ifndef PROGRAM_IMPL_H_61C1266F_B9C5_4EE4_A13C_9B9241A3683D
#define PROGRAM_IMPL_H_61C1266F_B9C5_4EE4_A13C_9B9241A3683D

#include <SDL_events.h>

#include "frog/program.h"
#include "frog/vec.h"
#include "renderer.h"
#include "sdl_initializer.h"
#include "sdl_window.h"


namespace frog {
    class scene;

    struct program::impl final {
        sdl_initializer sdl;
        sdl_window window;
        std::shared_ptr<scene> current_scene;

        bool quit = false;
        bool run_already_called = false;

        void process_events();
        void handle_event(const SDL_Event& event);
        vec<int> denormalize_pos(float x, float y);
    }; // struct program::impl

} // namespace frog

#endif // PROGRAM_IMPL_H_61C1266F_B9C5_4EE4_A13C_9B9241A3683D

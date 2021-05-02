//! \file       program_impl.cpp
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       18 April, 2021
//! \copyright  MIT License

#include "program_impl.h"

#include "frog/program.h"
#include "frog/scene.h"

namespace frog {

    void program::impl::process_events()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            handle_event(event);
        }
    }

    void program::impl::handle_event(const SDL_Event& event)
    {
        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
            case SDL_FINGERDOWN: {
                auto pos = denormalize_pos(event.tfinger.x, event.tfinger.y);
                current_scene->handle_finger_down_(pos);
                break;
            }
            case SDL_FINGERUP: {
                auto pos = denormalize_pos(event.tfinger.x, event.tfinger.y);
                current_scene->handle_finger_up_(pos);
                break;
            }
        }
    }

    vec<int> program::impl::denormalize_pos(float x, float y)
    {
        float width = static_cast<float>(window.renderer().resolution().x);
        float height = static_cast<float>(window.renderer().resolution().y);

        return {static_cast<int>(x * width),
                static_cast<int>(y * height)};
    }

} // namespace frog

// EOF

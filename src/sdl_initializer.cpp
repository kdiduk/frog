//! \file       sdl_initializer.cpp
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       27 March, 2021
//! \copyright  MIT License

#include "sdl_initializer.h"

#include <sstream>
#include <stdexcept>

#include <SDL.h>
#include <SDL_image.h>


namespace frog {

    sdl_initializer::sdl_initializer()
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::stringstream msg;
            msg << "Failed to initialize SDL: " << SDL_GetError();
            throw std::runtime_error(msg.str());
        }

        const auto img_flags = IMG_INIT_PNG;
        const auto img_status = IMG_Init(img_flags);
        if((img_status & img_flags) != img_flags)
        {
            std::stringstream msg;
            msg << "Failed to initialize SDL_image: " << IMG_GetError();
            throw std::runtime_error(msg.str());
        }
    }

    sdl_initializer::~sdl_initializer()
    {
        // Maybe registering the following calls with `atexit()`
        // is more robust, but first it should be found out
        // if that works correctly on Android.

        IMG_Quit();
        SDL_Quit();
    }

} // namespace frog

// EOF

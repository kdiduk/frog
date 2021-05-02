//! \file       sdl_window.h
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       28 March, 2021
//! \copyright  MIT License

#ifndef SDL_WINDOW_H_D142D0FC_8727_4822_B6EC_E683DCF0C074
#define SDL_WINDOW_H_D142D0FC_8727_4822_B6EC_E683DCF0C074

#include <memory>
#include <string>

#include <SDL_render.h>
#include <SDL_video.h>

#include "sdl_renderer.h"


namespace frog {

    //! \class  sdl_window
    //!
    //! \brief  Internal class that represents the window of the program.
    //!
    //! \details  This class just creates an SDL window and keeps it in a
    //! smart pointer. Only the class `program` uses `sdl_window` class.
    //!
    class sdl_window {
    public:
        sdl_window();
        ~sdl_window();

        sdl_renderer& renderer();
    private:
        using window_ptr = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

        static const std::string window_title;
        static constexpr int default_width = 960;
        static constexpr int default_height = 540;

        window_ptr make_window_ptr() const;
        SDL_Renderer* new_sdl_renderer() const;

        window_ptr m_window;
        sdl_renderer m_renderer;
    };
} // namespace frog

#endif // SDL_WINDOW_H_D142D0FC_8727_4822_B6EC_E683DCF0C074

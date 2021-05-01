//! \file       sdl_renderer.h
//! \date       2 April, 2021
//! \copyright  MIT License

#ifndef SDL_RENDERER_H_5CE14B59_DE66_4818_8CB4_8396B127FF66
#define SDL_RENDERER_H_5CE14B59_DE66_4818_8CB4_8396B127FF66

#include <cstdint>
#include <memory>

#include <SDL_render.h>

#include "renderer.h"


namespace frog {

    class texture;

    //! \details This class is a wrapper of SDL Renderer object.
    //! A renderer is tied to a window where it renders. Since there is only
    //! one main window in this program, there is a single renderer instance.
    //!
    class sdl_renderer : public renderer {
    public:
        sdl_renderer(SDL_Renderer* r, vec<short> resolution);
        ~sdl_renderer();

        vec<short> resolution() const override;
        void clear_target() const override;
        void render_texture(const texture& tx,
                const rect& dest_rect) const override;
        void present() const  override;

        operator SDL_Renderer*() const;
    private:
        struct renderer_deleter {
            void operator()(SDL_Renderer* r) {
                if (r) {
                    SDL_DestroyRenderer(r);
                }
            }
        };

        std::unique_ptr<SDL_Renderer, renderer_deleter> m_renderer;
        vec<short> m_resolution;
    }; // class sdl_renderer

} // namespace frog

#endif // SDL_RENDERER_H_5CE14B59_DE66_4818_8CB4_8396B127FF66

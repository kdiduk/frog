//! \file       texture_impl.cpp
//! \date       5 April, 2021
//! \copyright  MIT License

#include "texture_impl.h"

#include <sstream>
#include <stdexcept>

#include <SDL_image.h>
#include <SDL_render.h>

#include "frog/program.h"
#include "sdl_renderer.h"


namespace frog {

    void texture::impl::texture_deleter::operator()(SDL_Texture* t)
    {
        if (t) {
            SDL_DestroyTexture(t);
        }
    }

    texture::impl::impl(const std::string& file)
        : sdl_texture{create_texture(file)},
          id(sdl_texture.get())
    {
        if (SDL_QueryTexture(sdl_texture.get(), NULL, NULL, &width, &height)) {
            std::ostringstream msg;
            msg << "Failed to query texture attributes: " << SDL_GetError();
            throw std::runtime_error(msg.str());
        }
    }

    texture::impl::~impl() = default;

    texture::impl::sdl_texture_ptr
            texture::impl::create_texture(const std::string& file) const
    {
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>
                image(IMG_Load(file.c_str()), &SDL_FreeSurface);
        if (!image) {
            // NOTE: it's safe to pass null to SDL_FreeSurface
            std::ostringstream msg;
            msg << "Failed to load image file '" << file << "': "
                << IMG_GetError();
            throw std::runtime_error(msg.str());
        }

        const auto& renderer = static_cast<const sdl_renderer&>(
                program::instance()->renderer());

        SDL_Texture* tx = SDL_CreateTextureFromSurface(renderer, image.get());
        if (!tx) {
            std::ostringstream msg;
            msg << "Failed to create texture from image: " << SDL_GetError();
            throw std::runtime_error(msg.str());
        }

        return sdl_texture_ptr(tx);
    }

} // namespace frog

// EOF

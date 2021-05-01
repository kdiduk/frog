//! \file       texture_impl.h
//! \date       4 April, 2021
//! \copyright  MIT License

#ifndef TEXTURE_IMPL_H_DBACAE0E_5B3B_4368_AA27_9FFE42B32010
#define TEXTURE_IMPL_H_DBACAE0E_5B3B_4368_AA27_9FFE42B32010

#include "frog/texture.h"

#include <memory>

#include "texture_id.h"

struct SDL_Texture;

namespace frog {
    struct texture::impl {
        // Deleter class for destroying SDL_Texture held by `unique_ptr`
        struct texture_deleter {
            void operator()(SDL_Texture* t);
        };

        using sdl_texture_ptr = std::unique_ptr<SDL_Texture, texture_deleter>;

        impl(const std::string& file);
        ~impl();

        sdl_texture_ptr create_texture(const std::string& file) const;

        const sdl_texture_ptr sdl_texture;
        class texture::id id;
        int width;
        int height;
    }; // struct texture::impl

} // namespace frog

#endif // TEXTURE_IMPL_H_DBACAE0E_5B3B_4368_AA27_9FFE42B32010

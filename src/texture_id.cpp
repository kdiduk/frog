//! \file       texture_id.h
//! \date       6 April, 2021
//! \copyright  MIT License

#include "texture_id.h"

#include <SDL_render.h>

namespace frog {

    texture::id::id(SDL_Texture *sdl_texture)
            : m_sdl_texture(sdl_texture)
    {
    }

    texture::id::operator SDL_Texture*() const
    {
        return const_cast<id*>(this)->m_sdl_texture;
    }

} // namespace frog

// EOF

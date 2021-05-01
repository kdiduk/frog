//! \file       texture_id.h
//! \date       6 April, 2021
//! \copyright  MIT License

#ifndef TEXTURE_ID_H_39474F4F_7E90_4E16_B77A_68D74DBEB5F1
#define TEXTURE_ID_H_39474F4F_7E90_4E16_B77A_68D74DBEB5F1

#include "frog/texture.h"

struct SDL_Texture;

namespace frog {
    class texture::id {
    public:
        explicit id(SDL_Texture* sdl_texture);

        operator SDL_Texture*() const;

        id(const id&) = delete;
        id& operator=(const id&) = delete;
    private:
        SDL_Texture *m_sdl_texture;
    };
} // namespace frog

#endif // TEXTURE_ID_H_39474F4F_7E90_4E16_B77A_68D74DBEB5F1

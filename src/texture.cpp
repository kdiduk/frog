//! \file       texture.cpp
//! \date       4 April, 2021
//! \copyright  MIT License


#include "frog/texture.h"
#include "texture_impl.h"


namespace frog {
    texture::texture(const std::string& file)
        : m_pimpl{ std::make_unique<impl>(file) }
    {
    }

    texture::~texture() = default;

    int texture::width() const
    {
        return m_pimpl->width;
    }

    int texture::height() const
    {
        return m_pimpl->height;
    }

    const class texture::id& texture::id() const
    {
        return m_pimpl->id;
    }
} // namespace frog

// EOF

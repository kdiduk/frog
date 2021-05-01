//! \file       texture.h
//! \date       4 April, 2021
//! \copyright  MIT License

#ifndef TEXTURE_H_A60E1D31_093C_40AD_BF98_C8BBBDCDD24C
#define TEXTURE_H_A60E1D31_093C_40AD_BF98_C8BBBDCDD24C

#include <memory>
#include <string>

namespace frog {

    //! \brief Represents a texture that can be rendered.
    class texture {
    public:
        class id;

        texture(const std::string& file);
        ~texture();

        int width() const;
        int height() const;

        const class id& id() const;
    private:
        struct impl;
        std::unique_ptr<impl> m_pimpl;
    }; // class texture

} // namespace frog

#endif // TEXTURE_H_A60E1D31_093C_40AD_BF98_C8BBBDCDD24C

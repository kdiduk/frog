//! \file       vec.h
//! \date       11 April, 2021
//! \copyright  MIT License

#ifndef VEC_H_D7E30E94_4AA2_4E9A_9F92_0E6FE28DB69D
#define VEC_H_D7E30E94_4AA2_4E9A_9F92_0E6FE28DB69D

#include <type_traits>

namespace frog {

    //! \brief Template struct that represents 2d vector (x, y)
    //!
    //! \tparam T - type of vector's components (shall be arithmetic)
    //!
    template <typename T>
    struct vec final {
        static_assert(std::is_arithmetic<T>::value,
                "Template parameter T shall be an arithmetic type");

        T x = 0;
        T y = 0;

    }; // struct vec

} // namespace frog

#endif // VEC_H_D7E30E94_4AA2_4E9A_9F92_0E6FE28DB69D

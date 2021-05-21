//! \file vec_operations.h
//!
//! \brief Contains definition of vector operations
//! (e.g. +, +=, *, etc.) for vec<T> class.
//!
//! \date       19 May, 2021
//! \copyright  MIT License

#ifndef VEC_OPERATIONS_H_6F8955C3_A476_4C8B_BFC2_FFB1E18A5EDC
#define VEC_OPERATIONS_H_6F8955C3_A476_4C8B_BFC2_FFB1E18A5EDC

#include <stdexcept>

#include "frog/vec.h"

namespace frog {

    template<typename T>
    vec<T>& operator+=(vec<T>& v, const vec<T>& d)
    {
        v.x += d.x;
        v.y += d.y;
        return v;
    }

    template<typename T>
    vec<T> operator/(const vec<T>& v, const T& d)
    {
        if (d == 0) {
            throw std::invalid_argument("division by zero");
        }

        return vec<T>{ v.x / d, v.y / d };
    }

} // namespace frog

#endif // VEC_OPERATIONS_H_6F8955C3_A476_4C8B_BFC2_FFB1E18A5EDC

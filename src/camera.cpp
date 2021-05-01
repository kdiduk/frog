//! \file       camera.cpp
//! \date       12 April, 2021
//! \copyright  MIT License


#include "frog/camera.h"

namespace frog {

    const vec<int>& camera::position() const
    {
        return m_position;
    }

    vec<int>& camera::position()
    {
        return m_position;
    }

} // namespace frog

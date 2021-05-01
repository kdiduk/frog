//! \file       camera.h
//! \date       12 April, 2021
//! \copyright  MIT License

#ifndef CAMERA_H_82E2B37D_328C_4FE2_A4B1_BBD3CB2173CB
#define CAMERA_H_82E2B37D_328C_4FE2_A4B1_BBD3CB2173CB

#include "frog/vec.h"

namespace frog {

    //! \brief A camera can be set to a scene to show a portion
    //! of the view and to scroll.
    class camera {
    public:
        const vec<int>& position() const;
        vec<int>& position();
    private:
        vec<int> m_position{0, 0};
    }; // class camera

} // namespace frog

#endif // CAMERA_H_82E2B37D_328C_4FE2_A4B1_BBD3CB2173CB

//! \file       rect.h
//! \date       15 April, 2021
//! \copyright  MIT License


#ifndef RECT_H_0B786276_BA64_4FF4_9E7F_63485AF3EFCF
#define RECT_H_0B786276_BA64_4FF4_9E7F_63485AF3EFCF

#include "frog/vec.h"

namespace frog {

    //! \brief An axis-alligned rectangle with int coordinates.
    class rect final {
    public:
        rect() = default;
        rect(vec<int> pos, vec<int> sz);
        rect(int x, int y, int w, int h);

        const vec<int>& position() const;
        vec<int>& position();

        const vec<int>& size() const;
        vec<int>& size();

        //! \brief Checks whether a given point is inside the rect.
        bool contains(const vec<int>& pt) const;
    private:
        vec<int> m_position;
        vec<int> m_size;
    };

} // namespace frog

#endif // RECT_H_0B786276_BA64_4FF4_9E7F_63485AF3EFCF

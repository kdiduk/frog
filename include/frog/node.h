//! \file       node.h
//! \date       10 April, 2021
//! \copyright  MIT License

#ifndef NODE_H_8F5FA5A9_32FE_40E7_98A2_DE4FDC9BBD05
#define NODE_H_8F5FA5A9_32FE_40E7_98A2_DE4FDC9BBD05

#include "frog/vec.h"

namespace frog {
    class renderer;

    //! \brief Base class for all scene nodes.
    class node {
    public:
        virtual ~node();

    protected:

        friend class scene;
        virtual void render(const renderer& rr) const = 0;
        virtual void finger_down_event(vec<int> pos);
        virtual void finger_up_event(vec<int> pos);
    };
} // namespace frog

#endif // NODE_H_8F5FA5A9_32FE_40E7_98A2_DE4FDC9BBD05

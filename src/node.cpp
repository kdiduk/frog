//! \file       node.cpp
//! \date       21 April, 2021
//! \copyright  GPL-3.0 License

#include "frog/node.h"

namespace frog {

    node::~node() = default;

    void node::finger_down_event([[maybe_unused]] vec<int> pos)
    {
    }

    void node::finger_up_event([[maybe_unused]] vec<int> pos)
    {
    }

} // namespace frog

// EOF

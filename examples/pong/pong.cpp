//! \file       pong.cpp
//! \brief      Pong-like game example.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       02 May, 2021
//! \copyright  MIT License

#include <memory>

#include "frog/program.h"
#include "frog/scene.h"


int main(int argc, char** argv)
{
    frog::program program(argc, argv);
    return program.run(std::make_shared<frog::scene>());
}

// EOF

//! \file       pong.cpp
//! \brief      Part of 'pong' example from 'frog' project.
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       02 May, 2021
//! \copyright  MIT License

#include <memory>

#include "frog/program.h"
#include "game_scene.h"

int main(int argc, char** argv)
{
    frog::program program(argc, argv);
    return program.run(std::make_shared<pong::game_scene>());
}

// EOF

/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <mikayuu/mesh.hpp>

struct Player final : public mkyu::Mesh
{
    explicit Player() :
        Mesh{"Resource/Mesh/bunny.obj"}
    {}
    void update() override {
        position.x += 0.01;
        /*
        using mkyu::KeyState;
        using mkyu::KeyType;
        if (keyboard().state(KeyType::Left) == KeyState::Hold)
            position.x += 0.001;
        if (keyboard().state(KeyType::Right) == KeyState::Hold)
            position.x -= 0.001;
        if (keyboard().state(KeyType::Up) == KeyState::Hold)
            position.y += 0.001;
        if (keyboard().state(KeyState::Down) == KeyState::Hold)
            position.y -= 0.001;
            */
    }

    bool is_alive() override {
        return true;
    }
};

#endif

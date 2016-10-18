/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <mikayuu/mesh.hpp>
#include <mikayuu/keyboard.hpp>

struct Player : public mkyu::Mesh
{
    explicit Player() {
        read_from_file("Resource/Mesh/player.mym");
        position = mkyu::vector3d{};
    }
    void update() override {
        using mkyu::Keyboard;
        using mkyu::KeyState;
        using mkyu::KeyType;
        if (Keyboard::state(KeyType::Up) == KeyState::Hold)
            position.y += 0.001;
        if (Keyboard::state(KeyType::Down) == KeyState::Hold)
            position.y -= 0.001;
        if (Keyboard::state(KeyType::Left) == KeyState::Hold)
            position.x -= 0.001;
        if (Keyboard::state(KeyType::Right) == KeyState::Hold)
            position.x += 0.001;
    }
};

#endif

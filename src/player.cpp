/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <mikayuu/polygon.hpp>
#include <mikayuu/keyboard.hpp>

#include "player.hpp"

Player::Player() {
    m_mesh = mkyu::Mesh::load("Resource/Mesh/player.mym");
}

void Player::update() {
    auto is_pushed = [this](mkyu::KeyType type) {
        return mkyu::Keyboard::state(type) == mkyu::KeyState::Hold;
    };
    auto diff = mkyu::vector3d{};

    if (is_pushed(mkyu::KeyType::Up))
        diff.y = 0.001;
    if (is_pushed(mkyu::KeyType::Down))
        diff.y = -0.001;
    if (is_pushed(mkyu::KeyType::Left))
        diff.x = -0.001;
    if (is_pushed(mkyu::KeyType::Right))
        diff.x = 0.001;

    m_mesh->position = m_mesh->position + diff;
}

void Player::draw() const {
    m_mesh->draw();
}


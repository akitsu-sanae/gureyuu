/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <mikayuu/polygon.hpp>
#include <mikayuu/keyboard.hpp>

#include "player.hpp"

Player::Player(mkyu::Keyboard const& keyboard) :
    mkyu::Object(mkyu::vector2d{0.0, 0.0}),
    m_keyboard(keyboard)
{
    m_mesh = mkyu::Mesh::load("Resource/Mesh/player.mym");
}

void Player::update() {
    auto is_pushed = [this](mkyu::Keyboard::Type type) {
        return m_keyboard.state(type) == mkyu::Keyboard::State::Push;
    };
    auto diff = mkyu::vector2d{0.0, 0.0};
    if (is_pushed(mkyu::Keyboard::Type::Up))
        diff.y = 0.001;
    if (is_pushed(mkyu::Keyboard::Type::Down))
        diff.y = -0.001;
    if (is_pushed(mkyu::Keyboard::Type::Left))
        diff.x = -0.001;
    if (is_pushed(mkyu::Keyboard::Type::Right))
        diff.x = 0.001;
    m_mesh->position = m_mesh->position + diff;
}

void Player::draw() const {
    m_mesh->draw();
}


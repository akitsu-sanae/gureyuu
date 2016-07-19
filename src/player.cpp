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
    m_rect = std::make_shared<mkyu::Polygon<4>>(
            mkyu::vector2d{0.0, 0.0},
            std::array<mkyu::vector2d, 4>{{
            mkyu::vector2d{-0.1, -0.1},
            mkyu::vector2d{0.1, -0.1},
            mkyu::vector2d{0.1, 0.1},
            mkyu::vector2d{-0.1, 0.1}
            }},
            mkyu::Color{0, 100, 255, 255}
            );
    m_rect->blend(mkyu::BlendMode::Add);
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
    m_rect->position = m_rect->position + diff;
}

void Player::draw() const {
    m_rect->draw();
}


/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <mikayuu/game.hpp>
#include <mikayuu/scene.hpp>

#include "game_layer.hpp"

GameLayer::GameLayer(mkyu::Scene const& p) :
    mkyu::Layer(p)
{
    auto tri = std::make_shared<mkyu::Triangle>(
            std::array<mkyu::vector3d, 3>{{
            mkyu::vector3d{0.0, -0.5, 0.0},
            mkyu::vector3d{0.5, 0.2, 0.0},
            mkyu::vector3d{-0.5, 0.2, 0.0}}},
            mkyu::Color{155, 255, 255, 155}
            );
    tri->blend(mkyu::BlendMode::Alpha);
    add_object(tri);

    m_player = std::make_shared<Player>();
    add_object(m_player);
}

void GameLayer::on_update() {
    using namespace mkyu;
    if (mkyu::Keyboard::state(KeyType::Z) == KeyState::Hold) {
        auto shot = std::make_shared<Shot>();
        shot->position = m_player->position;
        m_shots.push_back(shot);
        add_object(shot);
    }
}

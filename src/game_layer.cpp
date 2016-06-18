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
    auto tri = std::make_shared<mkyu::Polygon<3>>(
            mkyu::vec2d{0.0, 0.0},
            std::array<mkyu::vec2d, 3>{{{0.0, -0.5}, {0.5, 0.2}, {-0.5, 0.2}}},
            mkyu::Color{155, 255, 255, 155}
            );
    tri->blend(mkyu::Polygon<3>::BlendMode::Alpha);
    add_object(tri);

    m_player = std::make_shared<Player>(parent().parent().keyboard());
    add_object(m_player);
}

void GameLayer::on_update() {
    using namespace mkyu;
    if (this->parent().parent().keyboard().state(Keyboard::Type::Z) == Keyboard::State::Hold) {
        auto shot = std::make_shared<Shot>(m_player->position());
        m_shots.push_back(shot);
        add_object(shot);
    }
}

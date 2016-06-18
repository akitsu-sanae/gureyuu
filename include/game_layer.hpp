/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_LAYER_HPP
#define GAME_LAYER_HPP

#include <memory>
#include <vector>

#include <mikayuu/layer.hpp>
#include <mikayuu/keyboard.hpp>
#include "player.hpp"
#include "shot.hpp"

struct GameLayer : public mkyu::Layer {
    explicit GameLayer(mkyu::Scene const&);
protected:
    void on_update() override;
    std::shared_ptr<Player> m_player;
    std::vector<std::shared_ptr<Shot>> m_shots;
};

#endif

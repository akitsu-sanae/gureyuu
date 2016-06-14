/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_LAYER_HPP
#define GAME_LAYER_HPP

#include <mikayuu/layer.hpp>
#include "player.hpp"

struct GameLayer : public mkyu::Layer {
    GameLayer(mkyu::Scene const&);
protected:
    void on_update() override {}
    std::shared_ptr<Player> m_player;
};

#endif

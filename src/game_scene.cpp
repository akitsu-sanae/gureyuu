/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "game_scene.hpp"
#include "game_layer.hpp"
using namespace Scene;

GameScene::GameScene(mkyu::Game const& p) :
    mkyu::Scene(p)
{
    auto layer = std::make_shared<GameLayer>(*this);
    add_layer(layer);
}


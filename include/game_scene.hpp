/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <mikayuu/scene.hpp>

#include "game_layer.hpp"

namespace Scene {

struct GameScene : public mkyu::Scene {
    explicit GameScene(mkyu::Game const& game) :
        mkyu::Scene(game)
    {
        add_layer("game", std::make_shared<GameLayer>(*this));
    }
protected:
    void on_update() override {}
};

}

#endif


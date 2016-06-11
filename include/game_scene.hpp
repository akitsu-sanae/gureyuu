/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include <mikayuu/scene.hpp>
#include <iostream>
#include "game_layer.hpp"

namespace Scene {

struct GameScene : public mkyu::Scene {

    GameScene(mkyu::Game const& p) :
        mkyu::Scene(p)
    {
        auto layer = std::make_shared<GameLayer>(*this);
        add_layer(layer);
    }
protected:
    void on_update() override {
    }
};

}

#endif


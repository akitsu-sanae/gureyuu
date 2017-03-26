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

struct GameScene final : public mkyu::Scene {
    using mkyu::Scene::Scene;
    void on_init() override {
        add_layer<GameLayer>();
    }
};

#endif


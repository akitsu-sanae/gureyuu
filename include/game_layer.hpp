/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_LAYER_HPP
#define GAME_LAYER_HPP
#include <iostream>

#include <mikayuu/layer.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/color.hpp>

#include "player.hpp"

struct GameLayer : public mkyu::Layer {
    using mkyu::Layer::Layer;

    void on_init() override {
        light().position = mkyu::vector3{0.0, 3.0, 5.0};
        light().light_color = mkyu::color{ 255, 255, 255 };
        player = &add_object<Player>();
    }

    void on_update() override {
    }
private:
    Player* player = nullptr;
};

#endif

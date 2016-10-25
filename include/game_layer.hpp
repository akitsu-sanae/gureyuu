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
#include <mikayuu/texture.hpp>
#include <mikayuu/camera.hpp>
#include <mikayuu/color.hpp>
#include <mikayuu/keyboard.hpp>

#include "player.hpp"
#include "shot.hpp"

struct GameLayer : public mkyu::Layer {
    explicit GameLayer(mkyu::Scene const& scene) :
        mkyu::Layer(scene)
    {
        light().position = mkyu::vector3d{0.0, 3.0, 5.0};
        light().light_color = mkyu::color{ 255, 0, 0 };
        player = &add_object<Player>();
    }
protected:
    void on_update() override {
        if (mkyu::Keyboard::state(mkyu::KeyType::Z) == mkyu::KeyState::Push)
            add_object<Shot>(player->position);
        std::cout << object_size() << std::endl;
    }
    Player* player = nullptr;
};

#endif

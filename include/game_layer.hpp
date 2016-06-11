/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_LAYER_HPP
#define GAME_LAYER_HPP

#include <mikayuu/layer.hpp>

struct GameLayer : public mkyu::Layer {
    GameLayer(mkyu::Scene const& p) :
        mkyu::Layer(p)
    {
        auto tri = std::make_shared<mkyu::Polygon<3>>(
                std::array<mkyu::vec2d, 3>{{{0.0, -0.5}, {0.5, 0.2}, {-0.5, 0.2}}},
                mkyu::Color{155, 255, 255, 155}
                );
        tri->blend(mkyu::Polygon<3>::BlendMode::Alpha);
        auto quad = std::make_shared<mkyu::Polygon<4>>(
                std::array<mkyu::vec2d, 4>{{{1.0, -1.0}, {-0.5, -0.5}, {-1.0, 1.0}, {1.0, 1.0}}},
                mkyu::Color{255, 155, 255, 155}
                );
        quad->blend(mkyu::Polygon<4>::BlendMode::Add);

        add_object(tri);
        add_object(quad);
    }
protected:
    void on_update() override {
    }
};

#endif

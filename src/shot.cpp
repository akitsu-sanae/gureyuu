/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "shot.hpp"

Shot::Shot() {
    m_rect = std::make_shared<mkyu::Rectangle>(
            std::array<mkyu::vector3d, 4> {{
            mkyu::vector3d{-0.05, -0.1, 0.0},
            mkyu::vector3d{0.05, -0.1, 0.0},
            mkyu::vector3d{0.05, 0.1, 0.0},
            mkyu::vector3d{-0.05, 0.1, 0.0}
            }},
            mkyu::Color{0, 200, 100, 100}
            );
    m_rect->blend(mkyu::BlendMode::Add);
}

void Shot::update() {
    m_rect->position = m_rect->position + mkyu::vector3d{0.0, 0.005, 0.0};
}

void Shot::draw() const {
    m_rect->draw();
}


/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "shot.hpp"

Shot::Shot(mkyu::vec2d const& pos) :
    mkyu::DrawableObject(pos)
{
    m_rect = std::make_shared<mkyu::Polygon<4>>(
            mkyu::vec2d{0.0, 0.0},
            std::array<mkyu::vec2d, 4> {{
            {-0.05, -0.1}, {0.05, -0.1}, {0.05, 0.1}, {-0.05, 0.1}
            }},
            mkyu::Color{0, 200, 100, 100}
            );
    m_rect->blend(mkyu::Polygon<4>::BlendMode::Add);
}

void Shot::draw() const {
    m_rect->draw();
    m_rect->position = m_rect->position + mkyu::vec2d{0.0, 0.005};
}


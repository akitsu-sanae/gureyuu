/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef SHOT_HPP
#define SHOT_HPP

#include <mikayuu/drawable_object.hpp>
#include <mikayuu/polygon.hpp>
#include <memory>

struct Shot : public mkyu::DrawableObject
{
    explicit Shot(mkyu::vec2d const&);
    void draw() const override;
    bool is_alive() const {
        return m_rect->position.y > -32.0;
    }
private:
    std::shared_ptr<mkyu::Polygon<4>> m_rect;
};

#endif

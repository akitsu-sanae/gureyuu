/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef SHOT_HPP
#define SHOT_HPP

#include <mikayuu/object.hpp>
#include <mikayuu/polygon.hpp>
#include <mikayuu/utility.hpp>

struct Shot final : public mkyu::Object
{
    explicit Shot(mkyu::vector2d const&);
    void update() override;
    void draw() const override;
    bool is_alive() const {
        return m_rect->position.y > -32.0;
    }
private:
    mkyu::ptr<mkyu::Rectangle> m_rect;
};

#endif

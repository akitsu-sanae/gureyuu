/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <mikayuu/drawable_object.hpp>
#include <mikayuu/polygon.hpp>
#include <mikayuu/keyboard.hpp>
#include <memory>

struct Player : public mkyu::DrawableObject
{
    explicit Player(mkyu::Keyboard const&);

    void draw() const override;
private:
    std::shared_ptr<mkyu::Polygon<4>> m_rect;
    mkyu::Keyboard const& m_keyboard;
};

#endif

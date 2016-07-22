/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>

#include <mikayuu/object.hpp>
#include <mikayuu/mesh.hpp>
#include <mikayuu/keyboard.hpp>
#include <mikayuu/utility.hpp>


struct Player : public mkyu::Object
{
    explicit Player(mkyu::Keyboard const&);

    void draw() const override;
    void update() override;
    mkyu::vector2d position() const {
        return m_mesh->position;
    }
private:
    std::unique_ptr<mkyu::Mesh> m_mesh;
    mkyu::Keyboard const& m_keyboard;
};

#endif

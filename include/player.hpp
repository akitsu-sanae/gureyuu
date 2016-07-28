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
#include <mikayuu/utility.hpp>


struct Player : public mkyu::Object
{
    explicit Player();

    void draw() const override;
    void update() override;
private:
    std::unique_ptr<mkyu::Mesh> m_mesh;
};

#endif

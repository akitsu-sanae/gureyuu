/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_HPP
#define GAME_HPP

#include <mikayuu/game.hpp>

struct Game : public mkyu::Game {
    explicit Game(mkyu::Game::Option const&);
    void on_update() override;
};

#endif

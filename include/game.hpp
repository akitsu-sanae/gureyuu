/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GAME_HPP
#define GAME_HPP

#include <mikayuu/game.hpp>

struct Game final : public mkyu::Game {
    explicit Game(mkyu::Game::Option const& option) :
        mkyu::Game(option)
    {}
    void on_init() override {
    }
    void on_update() override {
    }
};

#endif

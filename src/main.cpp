/*============================================================================
  Copyright (C) 2016 akitsu sanae
  https://github.com/akitsu-sanae/gureyuu
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "game.hpp"
#include "game_scene.hpp"

int main() {
    auto game = std::make_shared<Game>(mkyu::Game::Option{});

    while (game->is_alive()) {
        game->update();
        game->draw();
    }
}



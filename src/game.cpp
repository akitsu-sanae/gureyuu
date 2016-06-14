/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include "game.hpp"
#include "game_scene.hpp"

Game::Game(mkyu::Game::Option const& option) :
    mkyu::Game(option)
{
    change_scene(std::make_shared<Scene::GameScene>(*this));
}

void Game::on_update() {
}

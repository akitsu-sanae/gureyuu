#ifndef SHOT_HPP
#define SHOT_HPP

#include <mikayuu/mesh.hpp>
#include <mikayuu/vector.hpp>

struct Shot : mkyu::Mesh {
    explicit Shot(mkyu::vector3d const& pos) {
        read_from_file("Resource/Mesh/player.mym");
        position = pos;
        // color = mkyu::color{ 0, 255, 255 };
        Shot::number++;
    }
    static int number;
    void update() override {
        position.x -= 0.01;
    }

    bool is_alive() override {
        return position.x > -10.0;
    }
};

#endif

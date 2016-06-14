#include <mikayuu/polygon.hpp>
#include <mikayuu/keyboard.hpp>

#include "player.hpp"

Player::Player(mkyu::Keyboard const& keyboard) :
    mkyu::DrawableObject(mkyu::vec2d{0.0, 0.0}),
    m_keyboard(keyboard)
{
        m_rect = std::make_shared<mkyu::Polygon<4>>(
                mkyu::vec2d{0.0, 0.0},
                std::array<mkyu::vec2d, 4>{{
                {-0.1, -0.1}, {0.1, -0.1}, {0.1, 0.1}, {-0.1, 0.1}
                }},
                mkyu::Color{0, 100, 255, 255}
                );
        m_rect->blend(mkyu::Polygon<4>::BlendMode::Add);
}

void Player::draw() const {
        m_rect->draw();
        auto is_pushed = [this](mkyu::Keyboard::KeyType type) {
            return m_keyboard.state(type) == mkyu::Keyboard::KeyState::Push;
        };
        mkyu::vec2d diff = {};
        if (is_pushed(mkyu::Keyboard::KeyType::Up))
            diff.y = 0.001;
        if (is_pushed(mkyu::Keyboard::KeyType::Down))
            diff.y = -0.001;
        if (is_pushed(mkyu::Keyboard::KeyType::Left))
            diff.x = -0.001;
        if (is_pushed(mkyu::Keyboard::KeyType::Right))
            diff.x = 0.001;
        m_rect->position = m_rect->position + diff;
}


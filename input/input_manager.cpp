#include "input_manager.hpp"
#include <SFML/Window/Keyboard.hpp>

void InputManager::update() {
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}
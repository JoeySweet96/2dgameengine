#pragma once
#include <SFML/Graphics.hpp>
#include "../input/input_manager.hpp"
#include "../physics/physics.hpp"

class Game {
    public:
        virtual ~Game() = default;

        virtual void initialize(sf::RenderWindow& window) = 0;
        virtual void update(float dt, InputManager& input) = 0;
        virtual void render(sf::RenderWindow& window) = 0;
};
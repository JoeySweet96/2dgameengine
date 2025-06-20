#pragma once
#include <SFML/Graphics.hpp>
#include "input/input_manager.hpp"

class Game {
    public:
        Game();
        ~Game();

        void initialize();
        void update(float dt, InputManager& input);
        void render(sf::RenderWindow& window);

    private:
};
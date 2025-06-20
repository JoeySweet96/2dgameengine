#pragma once
#include <SFML/Graphics.hpp>
#include "../game.hpp"
#include "../debugger/debugger.hpp"
#include "../input/input_manager.hpp"

class Engine {
    public:
        Engine();
        void run();
    private:
        sf::RenderWindow window;
        Debugger debugger;
        Game game;
        InputManager input;

        void processEvents();
        void update(float dt);
        void render();
};
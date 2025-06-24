#pragma once
#include <SFML/Graphics.hpp>
#include "../game/game.hpp"
#include "../debugger/debugger.hpp"
#include "../input/input_manager.hpp"

class Engine {
    public:
        Engine(unsigned int width, unsigned int height);
        ~Engine();
        void run();

    private:
        sf::RenderWindow window;
        unsigned int windowWidth;
        unsigned int windowHeight;
    
        std::unique_ptr<Game> game;
        Debugger debugger;
        InputManager input;

        void processEvents();
        void update(float dt);
        void render();
};
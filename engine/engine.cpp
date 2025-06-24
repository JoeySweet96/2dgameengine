#include "engine.hpp"
#include "../ecs/ecs.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include "../game/pong.hpp"

Engine::Engine(unsigned int width, unsigned int height)
    : window(sf::VideoMode({width, height}), "Sweet Engine"),
      windowWidth(width), windowHeight(height) {
        window.setFramerateLimit(60);
        ImGui::SFML::Init(window);

        game = std::make_unique<Pong>();
    }

Engine::~Engine() {

}


// Event handling using SFML 3's std::optional
void Engine::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
}

void Engine::update(float dt) {
    input.update();
    game->update(dt, input);
    ImGui::SFML::Update(window, sf::seconds(dt));
}

void Engine::render() {
    window.clear();

    debugger.render();
    game->render(window);
    ImGui::SFML::Render(window);

    window.display();
}

void Engine::run() {
    
    game->initialize(window);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        processEvents();
        
        float deltaTime = deltaClock.restart().asSeconds();
        update(deltaTime);
        render();
    }
    
    ImGui::SFML::Shutdown();

}
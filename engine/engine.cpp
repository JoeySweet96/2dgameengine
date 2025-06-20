#include "engine.hpp"
#include "../ecs/ecs.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

Engine::Engine()
    : window(sf::VideoMode({640, 480}), "Sweet Engine") {
        window.setFramerateLimit(60);
        ImGui::SFML::Init(window);
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
    game.update(dt, input);
    ImGui::SFML::Update(window, sf::seconds(dt));
}

void Engine::render() {
    window.clear();

    debugger.render();
    game.render(window);
    ImGui::SFML::Render(window);

    window.display();
}

void Engine::run() {
    
    game.initialize();

    sf::Clock deltaClock;
    while (window.isOpen()) {
        processEvents();
        
        float deltaTime = deltaClock.restart().asSeconds();
        update(deltaTime);
        render();
    }
    
    ImGui::SFML::Shutdown();

}
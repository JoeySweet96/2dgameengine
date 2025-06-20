#include "game.hpp"
#include "ecs/ecs.hpp"
#include "physics/physics.hpp"
#include <SFML/Graphics.hpp>

Game::Game() {

}

Game::~Game() {

}

void Game::initialize() {
    physics::createWorldBounds(640.f, 480.f);
}

void Game::update(float dt, InputManager& input) {
    if(input.space) {
        physics::createBall(10.2f, 10.0f, 0.5f, physics::getWorld());
        physics::createBall(10.0f, 10.0f, 0.5f, physics::getWorld());
    }
   physics::step(dt);
}

void Game::render(sf::RenderWindow& window) {
    renderSystem(window);
}
#include "game.hpp"
#include "pong.hpp"

void Pong::initialize(sf::RenderWindow& window) {
    sf::Vector2u size = window.getSize();
    
    physics::createWorldBounds(size.x, size.y);
    
    ball = physics::createBall(size.x/2, size.y/2, .5, physics::world);
    b2Body* body = physicsBodies[ball].body;
    b2Vec2 velocity = body->GetLinearVelocity();
    velocity.x = 5.0f;
    velocity.y = -5.0f;
    body->SetLinearVelocity(velocity);

    player = physics::createRectangle(1, size.y / 2, 20, 100, physics::world);
    opponent = physics::createRectangle(size.x - 1, size.y / 2, 20, 100, physics::world);
    float trackinSpeed = 3.0f;
    aiComponents[opponent] = {trackinSpeed};

}

void Pong::handleInput(const InputManager& input) {
    b2Body* body = physicsBodies[player].body;
    b2Vec2 velocity = body->GetLinearVelocity();
    if(input.up) {
        velocity.y = -5.0f;   
    }
    else if(input.down) {
        velocity.y = 5.0f;
    }
    else {
        velocity.y = 0.0f;
    }
    body->SetLinearVelocity(velocity);  
}

void Pong::update(float dt, InputManager& input) {
   handleInput(input);
   aiSystem(ball);
   physics::step(dt);
}

void Pong::render(sf::RenderWindow& window) {
    renderSystem(window);
}
#include "ecs.hpp"


// ------------------- ECS Entities -------------------- //
Entity nextEntityId = 1;
std::vector<Entity> entities;

Entity createEntity() {
    Entity newEntity = nextEntityId++;
    entities.push_back(newEntity);
    return newEntity;
}


// Component storage
std::unordered_map<Entity, RenderComponent> renderComponents;
std::unordered_map<Entity, PhysicsBodyComponent> physicsBodies;
std::unordered_map<Entity, aiComponent> aiComponents;


// -------------------- ECS Systems --------------------//

void renderSystem(sf::RenderWindow& window) {
    for (auto& [entity, render] : renderComponents) {
        if (physicsBodies.find(entity) != physicsBodies.end()) {
            b2Body* body = physicsBodies[entity].body;
            b2Vec2 position = body->GetPosition();

            // Convert Box2D meters to SFML pixels (assume 30px = 1m)
            constexpr float SCALE = 30.f;
            render.shape->setPosition({position.x * SCALE, position.y * SCALE});

            window.draw(*render.shape);
        }
    }
}

void aiSystem(Entity ball) {
    b2Body* body = physicsBodies[ball].body;
    for(auto& [entity, ai] : aiComponents ) {
        if(physicsBodies.find(entity) != physicsBodies.end()) {
            float ballY = body->GetPosition().y;
            
            b2Body* paddle = physicsBodies[entity].body;
            float paddleY = paddle->GetPosition().y;
            b2Vec2 velocity = paddle->GetLinearVelocity();
            
            if(ballY > paddleY + 0.1f) {
                velocity.y = ai.trackingSpeed;
            } else if(ballY < paddleY - 0.1f) {
                velocity.y = -ai.trackingSpeed;
            } else {
                velocity.y = 0.0f;
            }
            paddle->SetLinearVelocity(velocity);
            
        }
    }
}


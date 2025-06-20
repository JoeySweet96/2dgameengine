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
std::unordered_map<Entity, CircleComponent> circleComponents;
std::unordered_map<Entity, PhysicsBodyComponent> physicsBodies;


// -------------------- ECS Systems --------------------//

void renderSystem(sf::RenderWindow& window) {
    for (auto& [entity, circle] : circleComponents) {
        if (physicsBodies.find(entity) != physicsBodies.end()) {
            b2Body* body = physicsBodies[entity].body;
            b2Vec2 position = body->GetPosition();

            // Convert Box2D meters to SFML pixels (assume 30px = 1m)
            constexpr float SCALE = 30.f;
            circle.circle.setPosition({position.x * SCALE, position.y * SCALE});

            window.draw(circle.circle);
        }
    }
}


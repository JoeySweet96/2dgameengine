#pragma once
#include <memory>
#include <cstdint>
#include <vector>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

constexpr float GRAVITY = 500.f; // pixels/sec^2
constexpr float TERMINAL_VELOCITY = 800.f;

using Entity = std::uint32_t;
Entity createEntity();
extern  std::vector<Entity> entities;

struct PhysicsBodyComponent {
    b2Body* body = nullptr;
};

struct RenderComponent {
    std::shared_ptr<sf::Shape> shape;
};

struct aiComponent {
    float trackingSpeed;
};

extern std::unordered_map<Entity, RenderComponent> renderComponents;
extern std::unordered_map<Entity, PhysicsBodyComponent> physicsBodies;
extern std::unordered_map<Entity, aiComponent> aiComponents;



void renderSystem(sf::RenderWindow& window);
void aiSystem(Entity trackingObj);
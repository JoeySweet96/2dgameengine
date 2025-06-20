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

struct CircleComponent {
    sf::CircleShape circle;
};

extern std::unordered_map<Entity, CircleComponent> circleComponents;
extern std::unordered_map<Entity, PhysicsBodyComponent> physicsBodies;


void updateMovement(float deltaTime);
void renderSystem(sf::RenderWindow& window);
void collisionSystem();
void boundsSystem(float windowWidth, float windowHeight);
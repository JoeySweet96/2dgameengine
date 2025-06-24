#pragma once
#include <box2d/box2d.h>
#include "../ecs/ecs.hpp"

const float SCALE = 30.0f;
namespace physics {
    extern b2World world;

    void initialize();
    void step(float dt, int velIterations = 8, int posIterations = 3);
    b2World& getWorld();
    Entity createBall(float x, float y, float radius, b2World& world);
    Entity createRectangle(float x, float y, float width, float height, b2World& world);
    void createWorldBounds(float windowWidth, float windowHeight);
};
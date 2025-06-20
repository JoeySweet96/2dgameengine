#include "physics.hpp"

// Gravity vector points downwards, standard Earth gravity.
b2Vec2 gravity(0.0f, 0.0f);
b2World physics::world(gravity);

void physics::initialize() {
    // No setup needed for now, world is statically defined.
}

void physics::step(float dt, int velocityIterations, int positionIterations) {
    world.Step(dt, velocityIterations, positionIterations);
}

b2World& physics::getWorld() {
    return world;
}

Entity physics::createBall(float x, float y, float radius, b2World& world) {
    
    Entity entity = createEntity();

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x / SCALE, y / SCALE);
    b2Body* body = world.CreateBody(&bodyDef);

    // Attach a circle shape
    b2CircleShape shape;
    shape.m_radius = radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.restitution = 0.9f; // bouncy

    body->CreateFixture(&fixtureDef);

    // Store in ECS
    physicsBodies[entity] = { body };
    circleComponents[entity] = { sf::CircleShape(radius * SCALE) }; // SCALE = pixels per meter
    circleComponents[entity].circle.setFillColor(sf::Color::Green);
    circleComponents[entity].circle.setOrigin({radius * SCALE, radius * SCALE});

    return entity;
}

void physics::createWorldBounds(float windowWidth, float windowHeight) {
    float width = 640.f / SCALE;
    float height = 480.f / SCALE;

    b2BodyDef groundDef;
    groundDef.position.Set(0.f, 0.f);
    b2Body* ground = physics::getWorld().CreateBody(&groundDef);

    b2EdgeShape edge;

    // Bottom
    edge.SetTwoSided(b2Vec2(0.f, height), b2Vec2(width, height));
    ground->CreateFixture(&edge, 0.f);

    // Top
    edge.SetTwoSided(b2Vec2(0.f, 0.f), b2Vec2(width, 0.f));
    ground->CreateFixture(&edge, 0.f);

    // Left
    edge.SetTwoSided(b2Vec2(0.f, 0.f), b2Vec2(0.f, height));
    ground->CreateFixture(&edge, 0.f);

    // Right
    edge.SetTwoSided(b2Vec2(width, 0.f), b2Vec2(width, height));
    ground->CreateFixture(&edge, 0.f);
}
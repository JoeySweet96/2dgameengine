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
Entity physics::createRectangle(float x, float y, float width, float height, b2World& world) {
    Entity entity = createEntity();

    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.position.Set(x / SCALE, y / SCALE);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox((width / 2) / SCALE, (height / 2) / SCALE);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.friction = 0.0f;
    fixtureDef.density = 0.0f;
    fixtureDef.restitution = 0.0f;
    body->CreateFixture(&fixtureDef);

    physicsBodies[entity] = { body };

    auto shape = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
    shape->setFillColor(sf::Color::Red);
    shape->setOrigin({width / 2.f, height / 2.f});
    renderComponents[entity] = { shape };

    return entity;
}

Entity physics::createBall(float x, float y, float radius, b2World& world) {
    
    Entity entity = createEntity();

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x / SCALE, y / SCALE);
    b2Body* body = world.CreateBody(&bodyDef);

    // Attach a circle shape
    b2CircleShape circleShape;
    circleShape.m_radius = radius;

    b2FixtureDef fixtureDef;
    fixtureDef.friction = 0.0f;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.restitution = 1.0f; // bouncy

    body->CreateFixture(&fixtureDef);

    // Store in ECS
    physicsBodies[entity] = { body };
    
    auto shape = std::make_shared<sf::CircleShape>(radius * SCALE);
    shape->setFillColor(sf::Color::Green);
    shape->setOrigin({radius * SCALE, radius * SCALE});
    renderComponents[entity] = { shape };

    return entity;
}

void physics::createWorldBounds(float windowWidth, float windowHeight) {
    float width = windowWidth / SCALE;
    float height = windowHeight / SCALE;

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
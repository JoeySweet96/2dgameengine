#include "debugger.hpp"
#include "imgui.h"
#include "../ecs/ecs.hpp"

void Debugger::render() {
    ImGui::Begin("Debugger");

    for(Entity entity : entities) {
        ImGui::Separator();
        ImGui::Text("Entity: %u", entity);

        if (physicsBodies.find(entity) != physicsBodies.end()) {
            b2Body* body = physicsBodies[entity].body;
            b2Vec2 pos = body->GetPosition();
            b2Vec2 vel = body->GetLinearVelocity();

            constexpr float SCALE = 30.f;
            ImGui::Text(" Position: (%.1f, %.1f)", pos.x * SCALE, pos.y * SCALE);
            ImGui::Text(" Velocity: (%.1f, %.1f)", vel.x, vel.y);
        }
        
    }

    ImGui::End();
}
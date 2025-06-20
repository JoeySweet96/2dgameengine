#pragma once

struct InputManager {
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool space = false;

    void update();
};

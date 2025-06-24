#include "game.hpp"

class Pong : public Game {
    public:
        void initialize(sf::RenderWindow& window) override;
        void update(float dt, InputManager& input) override;
        void render(sf::RenderWindow& window) override;
    private:
        void handleInput(const InputManager& input);
        Entity ball;
        Entity player;
        Entity opponent;
};
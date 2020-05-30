#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Player
{
private:
    sf::CircleShape playerModel;
    sf::Vector2f playerCenter;
    float speed;

public:
    Player();
    void playerMovement(float& deltaTime, sf::Vector2f& currentPlayerPos);
    void drawPlayer(sf::RenderWindow& window);
    void getPlayerPos(sf::Vector2f& currentPos, sf::Vector2f& playerCenter);
    void playerShooting(bool& isFired, sf::Time& bulletTime, sf::Clock& bulletClock, sf::Vector2f& velocity, sf::Vector2f& aimDirNorm);
};
#endif

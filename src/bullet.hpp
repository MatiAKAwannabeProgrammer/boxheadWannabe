#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Bullet
{
private:
    sf::CircleShape bulletModel;
    sf::Vector2f velocity;
    float maxSpeed;

public:
    Bullet(sf::Vector2f& playerPos, sf::Vector2f& velocity);
    void moveBullet(float& deltaTime);
    void drawBullet(sf::RenderWindow& window);
    void getBulletPos();
    sf::Vector2f bulletPosition;

};
#endif

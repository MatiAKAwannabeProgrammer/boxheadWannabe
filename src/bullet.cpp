#include "bullet.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

Bullet::Bullet(sf::Vector2f& playerCenter, sf::Vector2f& velocity)
{
    bulletModel.setRadius(5.f);
    bulletModel.setFillColor(sf::Color::Red);
    bulletModel.setPosition(playerCenter);
    this->velocity = velocity;
}

void Bullet::moveBullet(float& deltaTime)
{
    bulletModel.move(velocity * deltaTime);
}

void Bullet::drawBullet(sf::RenderWindow& window)
{
    window.draw(bulletModel);
}

void Bullet::getBulletPos()
{
    bulletPosition = bulletModel.getPosition();
}

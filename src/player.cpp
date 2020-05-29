#include "player.hpp"
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

Player::Player()
{
    playerModel.setRadius(50.f);
    playerModel.setFillColor(sf::Color::Magenta);
    playerModel.setPosition(sf::Vector2f(100.f, 100.f));
    speed = 300.f;
}

void Player::playerMovement(float& deltaTime, sf::Vector2f& currentPlayerPos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        playerModel.move(0, -speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        playerModel.move(0, speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        playerModel.move(-speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        playerModel.move(speed * deltaTime, 0);
    }

}

void Player::drawPlayer(sf::RenderWindow& window)
{
    window.draw(playerModel);
}

void Player::getPlayerPos(sf::Vector2f& currentPos, sf::Vector2f& playerCenter)
{
    currentPos = playerModel.getPosition();
    playerCenter = sf::Vector2f(currentPos.x + playerModel.getRadius(), currentPos.y + playerModel.getRadius());
}

void Player::playerShooting(bool& isFired, sf::Time& bulletTime, sf::Clock& bulletClock, sf::Vector2f& velocity, sf::Vector2f& aimDirNorm, float& bulletSpeed)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        bulletTime.asMilliseconds() >= 100){
        isFired = true;
        velocity = aimDirNorm * bulletSpeed;
        bulletClock.restart();
    }
}

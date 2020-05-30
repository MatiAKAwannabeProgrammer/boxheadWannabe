#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "bullet.hpp"

class Enemy
{
private:
    sf::CircleShape enemyModel;
    sf::FloatRect enemyBounds;
    float randX;
    float randY;

public:
    Enemy();
    void updateEnemy(float& deltaTime, sf::RenderWindow& window);
    void drawEnemy(sf::RenderWindow& window);
    void getEnemyPosition();
    void setRandomDir(float& randomX, float& randomY);
    void collision(std::vector<Bullet>& bulletVector, std::vector<Enemy>& enemyVector);
    sf::Vector2f enemyPosition;

};
#endif

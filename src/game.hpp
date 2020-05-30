#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "enemy.hpp"
#include <stdlib.h>
#include "bullet.hpp"
#include "player.hpp"
#include <cmath>

class Game
{
private:
    //Objects.
    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::Event event;
    Enemy * enemy;
    Bullet * bullet;
    Player player;
    sf::Clock enemyClock;
    sf::Clock deltaClock;
    sf::Clock directionClock;
    sf::Clock bulletClock;
    sf::Time directionTime;
    sf::Time bulletTime;   
    sf::Time enemyTime;
        // Variables.
    sf::Vector2f mousePos;
    sf::Vector2f velocity;
    sf::Vector2f currentPlayerPos;
    sf::Vector2f playerCenter;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;
    std::vector<Bullet> bulletVector;
    std::vector<Enemy> enemyVector;
    float deltaTime;
    float randomX;
    float randomY;
    bool isFired = false;

public:
    Game();
    bool running();
    void pollEvents();
    void update();
    void render();
    void createEnemy();
    void updateEnemy();
    void renderEnemy();
    void createBullet();
    void updateBullet();
    void renderBullet();
    void randomDirections();
    void calculations();

};
#endif

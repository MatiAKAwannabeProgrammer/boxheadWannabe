#include "game.hpp"
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>

Game::Game()
{
    window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "Test");
    window.setFramerateLimit(60);
}

bool Game::running()
{
    return window.isOpen();
}

void Game::pollEvents()
{
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update()
{
    // Setting the clocks.
    deltaTime = deltaClock.restart().asSeconds();
    enemyTime = enemyClock.getElapsedTime();
    bulletTime = bulletClock.getElapsedTime();
    directionTime = directionClock.getElapsedTime();

    // Getting mouse and player pos.
    mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
    player.getPlayerPos(currentPlayerPos, playerCenter);

    if (enemyTime.asSeconds() >= 2){ // Enemy spawn.
        enemyClock.restart();
        createEnemy();
    }
    if (directionTime.asSeconds() >= 1){ // Init the random x and y axis movements.
        directionClock.restart();
        randomDirections();
    }
    calculations(); // Calculate bullet movement.

    updateEnemy();
    player.playerMovement(deltaTime, currentPlayerPos);
    player.playerShooting(isFired, bulletTime, bulletClock, velocity, aimDirNorm);

    if (isFired){
        createBullet();
    }
    isFired = false;
    updateBullet();
    
    // Collision detection.
    enemy->collision(bulletVector, enemyVector);
}

void Game::render()
{
    window.clear();

    renderEnemy();
    player.drawPlayer(window);
    renderBullet();

    window.display();
}

void Game::createEnemy()
{
    enemy = new Enemy();
    enemyVector.push_back(*enemy);
}

void Game::updateEnemy()
{
    for (unsigned int i = 0; i < enemyVector.size(); i++){
        enemyVector[i].updateEnemy(deltaTime, window);
        enemyVector[i].getEnemyPosition();
    }
}

void Game::renderEnemy()
{
    for (unsigned int i = 0; i < enemyVector.size(); i++){
        enemyVector[i].drawEnemy(window);
    }
}

void Game::createBullet()
{
    bullet = new Bullet(playerCenter, velocity);
    bulletVector.push_back(*bullet);
}

void Game::updateBullet()
{
    for (unsigned int i = 0; i < bulletVector.size(); i++){
        bulletVector[i].moveBullet(deltaTime);
        bulletVector[i].getBulletPos();

        if (bulletVector[i].bulletPosition.x > window.getSize().x ||
            bulletVector[i].bulletPosition.y > window.getSize().y ||
            bulletVector[i].bulletPosition.x < 0 ||
            bulletVector[i].bulletPosition.y < 0){
            bulletVector.erase(bulletVector.begin() + i);
        }
    }
}

void Game::renderBullet()
{   
    for (unsigned int i = 0; i < bulletVector.size(); i++){
        bulletVector[i].drawBullet(window);
    }
}

void Game::randomDirections()
{
    for (unsigned int i = 0; i < enemyVector.size(); i++){
        randomX = (rand() % 400) - 400;     
        randomY = (rand() % 400) - 400;
        enemyVector[i].setRandomDir(randomX, randomY);
    }
}

void Game::calculations()
{
    aimDir = mousePos - playerCenter;
    aimDirNorm = aimDir / sqrtf(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

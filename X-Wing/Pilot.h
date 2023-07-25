#ifndef PILOT_H
#define PILOT_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"

class Pilot{
public:
    Pilot(const sf::Texture& xWingTexture, const sf::RenderWindow& window);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    

    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;

    void fireProjectiles();
    void updateProjectiles(sf::Time deltaTime);
    void drawProjectiles(sf::RenderWindow& window);

private:
    sf::Sprite xWingSprite;
    float moveSpeed = 1.0f;

    sf::Vector2f currentPosition;
    sf::Vector2f prevPosition;
    sf::Vector2f velocity;

    std::vector<std::unique_ptr<Projectile>> projectiles;
    float projectileSpeed = 800.0f; // Adjust the speed as per your preference

    bool hasFired = false;
    bool spaceBarPressedLastFrame = false;

    const sf::RenderWindow& windowRef;
 };

#endif
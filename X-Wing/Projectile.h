#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>


class Projectile {
public:
    Projectile(const sf::Vector2f& position, float speed);

    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);

    bool isActive() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    bool active;
};

#endif

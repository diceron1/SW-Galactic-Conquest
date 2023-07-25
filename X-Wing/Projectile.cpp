//X-wing gotta shoot
#include "Projectile.h"

Projectile::Projectile(const sf::Vector2f& position, float speed) : active(true) {
    shape.setRadius(3);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
    velocity = sf::Vector2f(0.0f, speed); // Projectile moves vertically with the given speed
}

void Projectile::update(sf::Time deltaTime) {
    if (active) {
        shape.move(velocity * deltaTime.asSeconds());
        if (shape.getPosition().y < 0) {
            active = false; // Deactivate the projectile when it goes off-screen (CURRENTLY ONLY WORKS FOR THE TOP OF THE SCREEN)
        }
    }
}

void Projectile::draw(sf::RenderWindow& window) {
    if (active) {
        window.draw(shape);
    }
}

bool Projectile::isActive() const {
    return active;
}

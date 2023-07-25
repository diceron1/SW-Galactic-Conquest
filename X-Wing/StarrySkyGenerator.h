#ifndef STARRYSKYGENERATOR_H
#define STARRYSKYGENERATOR_H

#include <SFML/Graphics.hpp>

class StarrySkyGenerator
{
public:
    StarrySkyGenerator(unsigned int width, unsigned int height);
    void update(const sf::Vector2f& playerVelocity, float dt);
    void draw(sf::RenderTarget& target);

private:
    sf::RenderTexture skyTexture;
    sf::Sprite skySprite;
    sf::Vector2f texturePosition;
    sf::Vector2f centerScreen;

    float spaceSpeed = 100;  //Adjust as needed

    void generateStarrySky(sf::RenderTexture& renderTexture);
};

#endif // STARRYSKYGENERATOR_H

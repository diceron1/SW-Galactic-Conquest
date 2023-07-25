//Pixel Perfect Collision Detection
#pragma once

#include <SFML/Graphics.hpp>

class PixelCollider
{
public:
    PixelCollider(sf::Texture const& texture);

    bool isCollidingWith(const PixelCollider& other, const sf::Sprite& thisSprite, const sf::Sprite& otherSprite) const;

private:
    sf::Image pixelMask;
    std::vector<std::vector<bool>> pixelMaskData;

    void createPixelMask(const sf::Texture& texture);
};
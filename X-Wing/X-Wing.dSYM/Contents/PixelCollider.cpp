#include "PixelCollider.h"

PixelCollider::PixelCollider(sf::Texture const& texture)
{
    createPixelMask(texture);
}

void PixelCollider::createPixelMask(const sf::Texture& texture)
{
    createPixelMask(texture);
}

bool PixelCollider::isCollidingWith(const PixelCollider& other, const sf::Sprite& thisSprite, const sf::Sprite& otherSprite) const
{
    
}
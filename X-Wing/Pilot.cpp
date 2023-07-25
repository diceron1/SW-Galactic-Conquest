#include "Pilot.h"

using namespace sf;

Pilot::Pilot(const sf::Texture& xWingTexture, const sf::RenderWindow& window) : windowRef(window){ 

    xWingSprite.setTexture(xWingTexture);

    sf::Vector2u textureSize = xWingTexture.getSize();   //Get the image size
    
    float originX = textureSize.x / 2.0f; //Calculate center of image
    float originY = textureSize.y / 2.0f; 
    
    xWingSprite.setOrigin(originX, originY);  //Reset origin to be center of image

    const sf::Vector2u windowSize = window.getSize();
    xWingSprite.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);  //Move player to center screen
    xWingSprite.setScale(0.15f, 0.15f);   //Resize to half size (0.5f)

    currentPosition = sf::Vector2f(0.f, 0.f);  //Reset center screen to 0,0
    prevPosition = currentPosition;



}

void Pilot::update(sf::Time deltaTime){

    prevPosition = currentPosition;
    
    sf::Vector2f newPosition = xWingSprite.getPosition();

    bool spaceBarPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){  //Move Left
        newPosition.x -= moveSpeed;
        velocity.x = -20.f;
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::D)){  //Move Right
        newPosition.x += moveSpeed;
        velocity.x = 20.f;
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::S)){  //Move Backward
        newPosition.y += moveSpeed;
        velocity.y = -10.f;
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::W)){  //Move Forward
        newPosition.y -= moveSpeed;
        velocity.y = -20.f;
    }

    if(spaceBarPressed && !spaceBarPressedLastFrame && !hasFired){
        fireProjectiles();
        hasFired = true;
    }

     if (!spaceBarPressed) {
        hasFired = false; // Reset the flag if the space bar is released
    }

    spaceBarPressedLastFrame = spaceBarPressed;




    //Check the bounds of the screen
    sf::Vector2u windowSize = windowRef.getSize();
    sf::FloatRect spriteBounds = xWingSprite.getGlobalBounds();

    if(newPosition.x < 0)
    {
        newPosition.x = 0;
    }
    if(newPosition.x + spriteBounds.width > windowSize.x)   //Check Right Border
    {
        newPosition.x = windowSize.x - spriteBounds.width;
        velocity.x = 50;
    }
    if(newPosition.x - spriteBounds.width < 0)   //Check Left Border
    {
        newPosition.x = 0 + spriteBounds.width;
        velocity.x = - 50;
    }
    if(newPosition.y < 0)
    {
        newPosition.y = 0;
    }
    if(newPosition.y + spriteBounds.height > windowSize.y)   //Check Bottom Border
    {
        newPosition.y = windowSize.y - spriteBounds.height;
        velocity.y = 10;
    }
    if(newPosition.y - spriteBounds.height < 0)  //Check Top Border
    {
        newPosition.y = 0 + spriteBounds.height;
        velocity.y = -50;
    }

    xWingSprite.setPosition(newPosition);  //Update sprite position only if it's within the screen bounds
}

sf::Vector2f Pilot::getPosition() const
{
    return xWingSprite.getPosition();
}

sf::Vector2f Pilot::getVelocity() const
{
    return velocity;
}

void Pilot::fireProjectiles() {
    sf::Vector2f leftFirePosition = xWingSprite.getPosition();
    leftFirePosition.x += 53.0f; // Adjust the position as per your sprite's dimensions
    leftFirePosition.y += -7.0f;

    sf::Vector2f rightFirePosition = xWingSprite.getPosition();
    rightFirePosition.x += -59.0f; // Adjust the position as per your sprite's dimensions
    rightFirePosition.y += -7.0f;
    
    projectiles.push_back(std::make_unique<Projectile>(leftFirePosition, -projectileSpeed)); // Left projectile
    projectiles.push_back(std::make_unique<Projectile>(rightFirePosition, -projectileSpeed)); // Right projectile

}

void Pilot::updateProjectiles(sf::Time deltaTime) 
{
    for (auto& projectile : projectiles) 
    {
        projectile->update(deltaTime);
    }
}

void Pilot::drawProjectiles(sf::RenderWindow& window) 
{
    for (const auto& projectile : projectiles)
    {
        projectile->draw(window);
    }
}

void Pilot::draw(sf::RenderWindow& window)
{
    window.draw(xWingSprite);
}

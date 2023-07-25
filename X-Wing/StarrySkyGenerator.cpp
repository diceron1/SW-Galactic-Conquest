#include "StarrySkyGenerator.h"

StarrySkyGenerator::StarrySkyGenerator(unsigned int width, unsigned int height) {
    skyTexture.create(width * 4, height * 4);
    generateStarrySky(skyTexture);
    skySprite.setTexture(skyTexture.getTexture());
    
     //Get the image size

    float hWidth = skyTexture.getTexture().getSize().x/ 2.0f; //Calculate center of image
    float hHeight = skyTexture.getTexture().getSize().y / 2.0f; 

    skySprite.setOrigin(hWidth, hHeight);  //Moves Sprite to corner of screen
    
    //sf::Vector2f centerScreen = skySprite.getOrigin();

    texturePosition = sf::Vector2f(0, 0);
}

void StarrySkyGenerator::update(const sf::Vector2f& playerVelocity, float dt) {
    texturePosition -= playerVelocity * dt;     // Move the texture in the opposite direction of the player's movement

    
    // Wrap the texture when reaching the edges to create a seamless scrolling effect
    sf::Vector2u textureSize = skyTexture.getSize();
    if (texturePosition.x < -textureSize.x)
        texturePosition.x += textureSize.x;
    if (texturePosition.y < -textureSize.y)
        texturePosition.y += textureSize.y;
    if (texturePosition.x > 0)
        texturePosition.x -= textureSize.x;
    if (texturePosition.y > 0)
        texturePosition.y -= textureSize.y;

    sf::err()<< "TexPosX: " << texturePosition.x <<"\n";
    sf::err()<< "TexPosY: " << texturePosition.y <<"\n";
}

void StarrySkyGenerator::draw(sf::RenderTarget& target) {
    // Set the texture position before drawing
    skySprite.setPosition(texturePosition);
    target.draw(skySprite);
}

void StarrySkyGenerator::generateStarrySky(sf::RenderTexture& renderTexture) {
    // Set the render texture as the active rendering target
    renderTexture.setActive(true);

    // Clear the render texture with a black background (you can use any color you want)
    renderTexture.clear(sf::Color::Black);

    // Randomly generate white dots representing stars on the render texture
    sf::Vector2u textureSize = renderTexture.getSize();
    sf::Vector2f position;

    sf::RectangleShape star(sf::Vector2f(1.0f, 1.0f)); // Each star is a 1x1 pixel rectangle

    for (int i = 0; i < 1000; ++i) // You can adjust the number of stars as per your preference
    {
        // Generate random positions for stars
        position.x = static_cast<float>(std::rand() % textureSize.x);
        position.y = static_cast<float>(std::rand() % textureSize.y);

        star.setPosition(position);
        star.setFillColor(sf::Color::White);

        // Draw each star on the render texture
        renderTexture.draw(star);
    }

    // Reset the active rendering target to the default window
    renderTexture.setActive(false);
}
